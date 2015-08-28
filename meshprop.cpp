#include <vcg/complex/complex.h>

// #include <wrap/io_trimesh/import_off.h>
#include <wrap/io_trimesh/import.h>

#include <vcg/complex/algorithms/inertia.h>
#include <vcg/complex/algorithms/create/platonic.h>

#include <vcg/complex/algorithms/stat.h>
#include <vcg/complex/algorithms/update/bounding.h>

#include <iostream>

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

int main( int argc, char **argv )
{
  if (argc != 2) {
    std::cout << "missing argument";
    return 1;
  }

  MyMesh mesh;

  if (vcg::tri::io::Importer<MyMesh>::Open(mesh, argv[1]) != 0) {
    std::cout << "can't import mesh";
    return 1;
  }

  std::cout << "{" << std::endl;

  vcg::tri::Inertia<MyMesh> Ib(mesh);
  std::cout << "  \"volume\" : " << Ib.Mass() << "," << std::endl;

  std::cout << "  \"area\" : " << vcg::tri::Stat<MyMesh>::ComputeMeshArea(mesh) << "," << std::endl;

  vcg::tri::UpdateBounding<MyMesh>::Box(mesh);

  std::cout << "  \"bbox\" : {" << std::endl;

  std::cout << "    \"x\" : " << mesh.bbox.DimX() << "," << std::endl;
  std::cout << "    \"y\" : " << mesh.bbox.DimY() << "," << std::endl;
  std::cout << "    \"z\" : " << mesh.bbox.DimZ() << std::endl;

  std::cout << "  }" << std::endl;

  std::cout << "}" << std::endl;

  return 0;
}
