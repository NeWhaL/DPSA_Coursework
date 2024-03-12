#include "../../include/matrixGraph.hpp"

using namespace std;

std::vector<std::pair<int, std::vector<std::pair<int, int>>>> MatrixGraph::GetGraph()
{
  return graph;
}

int MatrixGraph::Size() const { return graph.size(); }

int MatrixGraph::DoubleOperatorSquareBrackets(int value_start_vertex, int index)
{
  return 0;
}

bool MatrixGraph::CheckVertex(int vertex) const
{
  for(const auto& search_vertex : graph)
    if(search_vertex.first == vertex)
      return true;
  return false;
}

bool MatrixGraph::CheckVertexs(int vertex_1, int vertex_2) const
{
  return CheckVertex(vertex_1) and CheckVertex(vertex_2);
}

void MatrixGraph::AddVertex(int vertex)
{
  if(CheckVertex(vertex)) return;
  graph.push_back({vertex, vector<pair<int, int>>(graph.size())});
  for(int i = 0; i < graph.size(); ++i)
  {
    graph[i].second.push_back({});
    for(int j = 0; j < graph.size(); ++j)
      graph[i].second[j] = {graph[j].first, 0}; 
  }
}

void MatrixGraph::AddEdge(int vertex_1, int vertex_2, int value_rib = 1)
{
  if(vertex_1 == vertex_2) return;
  if(not CheckVertexs(vertex_1, vertex_2))
  {
    cout << "Ребро не добавлено так как нету одной из вершин...\n";
    return;
  }
  if (SearchEdge(vertex_1, vertex_2))
  {
    cout << "Ребро между вершинами " << vertex_1 << " и " << vertex_2 << 
    " уже существует.\n";
    return;
  }

  for(auto& rows : graph)
  {
    if(rows.first == vertex_1)
      for(auto& cols : rows.second)
        if(cols.first == vertex_2)
          cols.second = value_rib;
    if(rows.first == vertex_2)
      for(auto& cols : rows.second)
        if(cols.first == vertex_1)
          cols.second = value_rib;
  }
}

//Вернет не 0, если есть ребро между этими вершинами и 0, если нету.
int MatrixGraph::SearchEdge(int vertex_1, int vertex_2) const
{
  if(not CheckVertexs(vertex_1, vertex_2)) return 0;
  for(auto& rows : graph)
  {
    if(rows.first == vertex_1)
      for(auto& cols : rows.second)
      {
        if(cols.first == vertex_2)
          return cols.second; 
      }
  }
  return 0;
}

void MatrixGraph::Print() const
{
  cout << "\t\t";
  for (int i = 0; i < graph.size(); ++i)
    cout << i << '\t'; 
  cout << "\n\t\t";
  for(const auto& vertex : graph)
    cout << vertex.first << '\t';
  cout << endl;

  for (int i = 0; i < graph.size(); ++i)
  { 
    cout << "index " << i << " - " << graph[i].first << '\t';
    for(const auto& vertex_2 : graph[i].second)
      cout << vertex_2.second << '\t';
    cout << endl;
  }
}

void MatrixGraph::DeleteVertex(int vertex)
{
  if(not CheckVertex(vertex)) return;

  auto delete_vertex = graph.begin();
  int delete_vertex_by_index_in_cols = 0;
  for( ; (*delete_vertex).first != vertex; ++delete_vertex_by_index_in_cols, ++delete_vertex);
  graph.erase(delete_vertex);

  for(auto rows = graph.begin(); rows != graph.end(); ++rows)
    rows->second.erase(rows->second.begin() + delete_vertex_by_index_in_cols);
}