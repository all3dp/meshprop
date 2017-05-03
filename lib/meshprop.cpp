/*
#include <vcg/complex/complex.h>

// #include <wrap/io_trimesh/import_off.h>
#include <wrap/io_trimesh/import.h>

#include <vcg/complex/algorithms/inertia.h>
#include <vcg/complex/algorithms/create/platonic.h>

#include <vcg/complex/algorithms/stat.h>
#include <vcg/complex/algorithms/update/bounding.h>


#include <node.h>
#include <v8.h>

class MyEdge;
class MyFace;
class MyVertex;
struct MyUsedTypes : public vcg::UsedTypes<	vcg::Use<MyVertex>   ::AsVertexType,
                                            vcg::Use<MyEdge>     ::AsEdgeType,
                                            vcg::Use<MyFace>     ::AsFaceType>{};

class MyVertex  : public vcg::Vertex<MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Normal3f, vcg::vertex::BitFlags  >{};
class MyFace    : public vcg::Face< MyUsedTypes, vcg::face::FFAdj, vcg::face::Normal3f, vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyEdge    : public vcg::Edge<MyUsedTypes>{};
class MyMesh    : public vcg::tri::TriMesh< std::vector<MyVertex>, std::vector<MyFace> , std::vector<MyEdge>  > {};

using namespace v8;

void Method(const v8::FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = Isolate::GetCurrent();
  HandleScope scope(isolate);

  if (args.Length() < 2) {
    isolate->ThrowException(Exception::TypeError(
        String::NewFromUtf8(isolate, "Wrong number of arguments")));
    return;
  }

  MyMesh mesh;

  if (vcg::tri::io::Importer<MyMesh>::Open(mesh, *v8::String::Utf8Value(args[0]->ToString())) != 0) {
    Local<Function> callback = Local<Function>::Cast(args[1]);
    const unsigned argc = 1;
    Local<Value> argv[argc] = { v8::Exception::Error(String::NewFromUtf8(isolate, "can't import mesh")) };
    callback->Call(isolate->GetCurrentContext()->Global(), argc, argv);

    return;
  }

  vcg::tri::Inertia<MyMesh> Ib(mesh);

  Local<Object> obj = Object::New(isolate);

  obj->Set(String::NewFromUtf8(isolate, "volume"), Number::New(isolate, Ib.Mass()));
  obj->Set(String::NewFromUtf8(isolate, "area"), Number::New(isolate, vcg::tri::Stat<MyMesh>::ComputeMeshArea(mesh) ));

  vcg::tri::UpdateBounding<MyMesh>::Box(mesh);

  Local<Object> bbox = Object::New(isolate);
  bbox->Set(String::NewFromUtf8(isolate, "x"), Number::New(isolate, mesh.bbox.DimX()));
  bbox->Set(String::NewFromUtf8(isolate, "y"), Number::New(isolate, mesh.bbox.DimY()));
  bbox->Set(String::NewFromUtf8(isolate, "z"), Number::New(isolate, mesh.bbox.DimZ()));

  obj->Set(String::NewFromUtf8(isolate, "bbox"), bbox);

  Local<Function> callback = Local<Function>::Cast(args[1]);
  const unsigned argc = 2;
  Local<Value> argv[argc] = { v8::Null(isolate) , obj };
  callback->Call(isolate->GetCurrentContext()->Global(), argc, argv);

}

void init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "parse", Method);
}

NODE_MODULE(meshprop, init);
*/



#include <node.h>

namespace meshprop {

  using v8::Exception;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::String;
  using v8::Value;

  // This is the implementation of the "add" method
  // Input arguments are passed using the
  // const FunctionCallbackInfo<Value>& args struct
  void Add(const FunctionCallbackInfo<Value>& args) {
    Isolate* isolate = args.GetIsolate();

    // Check the number of arguments passed.
    if (args.Length() < 2) {
      // Throw an Error that is passed back to JavaScript
      isolate->ThrowException(Exception::TypeError(
              String::NewFromUtf8(isolate, "Wrong number of arguments")));
      return;
    }

    // Check the argument types
    if (!args[0]->IsNumber() || !args[1]->IsNumber()) {
      isolate->ThrowException(Exception::TypeError(
              String::NewFromUtf8(isolate, "Wrong arguments")));
      return;
    }

    // Perform the operation
    double value = args[0]->NumberValue() + args[1]->NumberValue();
    Local<Number> num = Number::New(isolate, value);

    // Set the return value (using the passed in
    // FunctionCallbackInfo<Value>&)
    args.GetReturnValue().Set(num);
  }

  void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "parse", Add);
  }

  NODE_MODULE(meshprop, Init)

}  // namespace meshprop
