#include "../../include/listGraph.hpp"

using namespace std;

std::vector<std::pair<int, std::vector<std::pair<int, int>>>> ListGraph::GetGraph()
{
  return graph;
}

int ListGraph::Size() const { return graph.size(); }

int ListGraph::DoubleOperatorSquareBrackets(int value_start_vertex, int index)
{
  if(not CheckVertex(value_start_vertex))
    return -1;
  
  for (const auto& search_vertex : graph)
    if (search_vertex.first == value_start_vertex)
      if(index > search_vertex.second.size()) return 0;
      else return search_vertex.second[index].second;
  return 0;
}

bool ListGraph::CheckVertex(int vertex) const
{
  for (const auto& search_vertex : graph)
    if (search_vertex.first == vertex)
      return true;
  return false;
}

bool ListGraph::CheckVertexs(int vertex_1, int vertex_2) const
{
  return CheckVertex(vertex_1) and CheckVertex(vertex_2);
}

void ListGraph::Print() const
{
  for (int i = 0; i < graph.size(); ++i)
  { 
    cout << "index " << i << " - " << graph[i].first << '\t';
    for(const auto& vertex_2 : graph[i].second)
      cout << vertex_2.first << '\t';
    cout << endl;
  }
}

void ListGraph::AddEdge(int vertex_1, int vertex_2, int value_rib = 1)
{ 
  if(vertex_1 == vertex_2) return;
  if(not CheckVertexs(vertex_1, vertex_2))
  {
    cout << "Ребро не добавлено так как нету одной из вершин...\n";
    return;
  }
  if(SearchEdge(vertex_1, vertex_2) != 0) return;

  for(auto& search_vertex : graph)
  {
    if(search_vertex.first == vertex_1)
      search_vertex.second.push_back({vertex_2, value_rib});
    if(search_vertex.first == vertex_2)
      search_vertex.second.push_back({vertex_1, value_rib});
  } 
}

void ListGraph::AddVertex(int vertex)
{
  for(const auto& search_vertex : graph)
    if(search_vertex.first == vertex) return;
  graph.push_back({vertex, {}});
}

int ListGraph::SearchEdge(int vertex_1, int vertex_2) const
{
  if (not CheckVertexs(vertex_1, vertex_2)) return 0;
  for (const auto& vertex : graph)
    if(vertex.first == vertex_1)
      for (const auto& edge : vertex.second)
        if (edge.first == vertex_2)
          return edge.second;
  return 0;
}

void ListGraph::DeleteVertex(int vertex)
{
  if (not CheckVertex(vertex)) return;
  int count = 0;
  for(auto& search_vertex : graph)
  {
    if(search_vertex.first == vertex)
      graph.erase(graph.begin() + count);
    count++;
  } 

  for (int i = 0; i < graph.size(); ++i)
    for (int j = 0; j < graph[i].second.size(); ++j)
      if ((graph[i]).second[j].first == vertex)
      {
        graph[i].second.erase(get<EDGES>(graph[i]).begin() + j);
        break;
      }
}