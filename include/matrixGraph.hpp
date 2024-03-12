#ifndef MATRIXGRAPH
#define MATRIXGRAPH
#include "graph.hpp"

class MatrixGraph : public Graph
{
  std::vector<std::pair<int, std::vector<std::pair<int, int>>>> graph;
  
  bool CheckVertex(int vertex) const;
  bool CheckVertexs(int vertex_1, int vertex_2) const;

public:
  MatrixGraph(): Graph() {};
  ~MatrixGraph() = default;
  std::vector<std::pair<int, std::vector<std::pair<int, int>>>> GetGraph();
  void Print() const;
  void AddEdge(int vertex_1, int vertex_2, int value_rib);
  void AddVertex(int vertex);
  int SearchEdge(int vertex_1, int vertex_2) const;
  void DeleteVertex(int vertex);
  int Size() const; 
  int DoubleOperatorSquareBrackets(int value_start_vertex, int index);
};

#endif