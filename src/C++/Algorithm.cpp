#include "../../include/Algorithm.hpp"
#include <limits.h>

using namespace std;

void AlgorithmDijkstra(Graph* graph, int index_vertex)
{
  vector<bool> visited(graph->Size(), false);
  vector<int> min_paths(graph->Size());

  for(int i = 0; i < graph->Size(); i++)
      min_paths[i] = graph->GetGraph()[index_vertex].second[i].second;
  min_paths[index_vertex] = 0;
  int index=0,u=0;
  for (int i = 0; i < graph->Size(); i++)
  {
      int min = INT_MAX;
      for (int j = 0; j < graph->Size(); j++)
      {
          if (not visited[j] and min_paths[j] < min)
          {
              min = min_paths[j]; 
              index = j;
          }
      }
      u = index;
      visited[u] = true;
      for(int j = 0; j < graph->Size(); j++)
      {
          if (not visited[j] and graph->GetGraph()[u].second[j].second != INT_MAX and 
                  min_paths[u] != INT_MAX and (min_paths[u] + graph->GetGraph()[u].second[j].second < min_paths[j]))
          {
              min_paths[j] = min_paths[u] + graph->GetGraph()[u].second[j].second;
          }
      }
  }
  cout<<"Стоимость пути из начальной вершины до остальных(Алгоритм Дейкстры):\t\n";
  for (int i=0; i < graph->Size(); ++i)
  {
      if (min_paths[i] != INT_MAX)
          cout<< index_vertex <<" -> "<< i << " = " << min_paths[i] << endl;
      else 
          cout<< index_vertex << " -> " << i << " = " << "маршрут недоступен" << endl;
  }
}