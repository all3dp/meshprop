#include <vcg/complex/complex.h>
#include <wrap/io_trimesh/import.h>
#include <vcg/complex/algorithms/inertia.h>
#include <vcg/complex/algorithms/create/platonic.h>
#include <vcg/complex/algorithms/stat.h>
#include <vcg/complex/algorithms/update/bounding.h>

#include <napi.h>

class MyEdge;
class MyFace;
class MyVertex;
struct MyUsedTypes : public vcg::UsedTypes<vcg::Use<MyVertex>::AsVertexType,
                                           vcg::Use<MyEdge>  ::AsEdgeType,
                                           vcg::Use<MyFace>  ::AsFaceType>{};

class MyVertex  : public vcg::Vertex<MyUsedTypes, vcg::vertex::Coord3f, vcg::vertex::Normal3f, vcg::vertex::BitFlags  >{};
class MyFace    : public vcg::Face< MyUsedTypes, vcg::face::FFAdj, vcg::face::Normal3f, vcg::face::VertexRef, vcg::face::BitFlags > {};
class MyEdge    : public vcg::Edge<MyUsedTypes>{};
class MyMesh    : public vcg::tri::TriMesh< std::vector<MyVertex>, std::vector<MyFace> , std::vector<MyEdge>  > {};

void Parse(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
  Napi::Function cb = info[1].As<Napi::Function>();

  if (info.Length() < 2) {
    Napi::TypeError::New(env, "Wrong number of arguments").ThrowAsJavaScriptException();
    return;
  }

  MyMesh mesh;

  Napi::String path = info[0].As<Napi::String>();

  if (vcg::tri::io::Importer<MyMesh>::Open(mesh, path.Utf8Value().c_str()) != 0) {
    Napi::Error err = Napi::Error::New(env, "Can't import mesh");
    cb.Call(env.Global(), { err.Value(), env.Null() });
    return;
  }

  vcg::tri::Inertia<MyMesh> Ib(mesh);

  Napi::Object obj = Napi::Object::New(env);

  obj.Set("volume", Ib.Mass());
  obj.Set("area", vcg::tri::Stat<MyMesh>::ComputeMeshArea(mesh));

  vcg::tri::UpdateBounding<MyMesh>::Box(mesh);

  Napi::Object bbox = Napi::Object::New(env);
  bbox.Set("x", mesh.bbox.DimX());
  bbox.Set("y", mesh.bbox.DimY());
  bbox.Set("z", mesh.bbox.DimZ());

  obj.Set("bbox", bbox);

  cb.Call(env.Global(), { env.Null(), obj });
  return;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
  exports.Set("parse", Napi::Function::New(env, Parse));
  return exports;
}

NODE_API_MODULE(meshprop, Init);
