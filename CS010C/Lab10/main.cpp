#include <cstring>
#include <iostream>
#include "Graph.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "Usage error: expected <executable> <input>" << std::endl;
    exit(1);
  }
  
  std::ifstream ifs(argv[1]);
  if (!ifs)
  {
    std::cout << "Input file not found." << std::endl;
    exit(1);
  }
  
  Graph g(ifs);
  ifs.close();
  g.bfs();

  g.print_all();

  //string filename = strcat(argv[1] , ".dot");
  //g.output_graph(filename);
  std::cout << "The End." << std::endl;
  
  return 0;
}