#include "../../include/main.hpp"
#include "../../include/matrixGraph.hpp"
#include "../../include/listGraph.hpp"
#include "../../include/Algorithm.hpp"

using namespace std;

void TestGraph(Graph* graph);

int main()
{
  srand(time(nullptr));
  Graph* graph = new MatrixGraph;
  TestGraph(graph);
  AlgorithmDijkstra(graph, 6);
  
  return 0;
}

void TestGraph(Graph* graph)
{
  const int amount_vertex = 10;
  //Добавление вершин в граф
  for(int i = 0; i < amount_vertex; ++i)
    graph->AddVertex(i);
  cout << "После добавления всех вершин в граф\n";
  graph->Print();
  for(int i = 0; i < amount_vertex; ++i)
  {
    graph->AddEdge(i, rand() % amount_vertex, i + 5);
    graph->AddEdge(rand() % amount_vertex, rand() % amount_vertex, 1);
    graph->AddEdge(i - 2, i * 2 - 1, i + 7);
  }
  cout << "Добавлены ребра\n";
  graph->Print();
  for(int i = 0; i < amount_vertex; ++i)
  {
    cout << "Значение ребра между " << i << " и " << i + 1 << " == " << graph->SearchEdge(i, i + 1) << endl;
    cout << "Значение ребра между " << i - 2 << " и " << i << " == " << graph->SearchEdge(i - 2, i) << endl;
    cout << "Значение ребра между " << i << " и " << i << " == " << graph->SearchEdge(i, i) << endl;
  }
  cout << "Перед удалением вершин граф выглядит следующим образом:\n";
  graph->Print();
  graph->DeleteVertex(1);
  graph->DeleteVertex(4);
  graph->DeleteVertex(10);
  graph->DeleteVertex(7);
  cout << "После удаление вершин граф выглядит так:\n";
  graph->Print();
}