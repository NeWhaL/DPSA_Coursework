#ifndef GRAPH
#define GRAPH
#include "main.hpp"

const int VERTEX = 0;
const int EDGES = 1;

class Graph
{
public:
  Graph() = default;
  virtual ~Graph() = default;
  virtual std::vector<std::pair<int, std::vector<std::pair<int, int>>>> GetGraph() = 0;
  virtual void Print() const = 0;
  virtual void AddEdge(int vertex_1, int vertex_2, int value_rib) = 0;
  virtual void AddVertex(int vertex) = 0;
  virtual int SearchEdge(int vertex_1, int vertex_2) const = 0;
  virtual void DeleteVertex(int vertex) = 0;
  virtual int Size() const = 0;
  virtual int DoubleOperatorSquareBrackets(int value_start_vertex, int index) = 0;
};

#endif