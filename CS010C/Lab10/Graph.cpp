#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include "Graph.h"


Graph::Graph(){
    vertices = std::vector<Vertex>();
}

Graph::Graph(std::ifstream &ifs){
    std::string entry;
    while (ifs >> entry){
        
    }
}