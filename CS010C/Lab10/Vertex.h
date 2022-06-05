// #ifndef VERTEX_H
// #define VERTEX_H
// #include <cstdlib>
// #include <utility>
// #include <list>
// #include <string>

// #define INT_MAX 2147483647;

// class Vertex {
//     private:
//         int distance;
//         std::list<std::pair<int, int>> neighbors;
//         std::string label;
//         Vertex *prev;
//     public:
// };

// #endif
#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <list>
#include <map>
#include <climits>

class Vertex {
public:
  std::list<std::pair<int, int> > neighbors;
  std::string label;
  int distance;
  std::string color;
  Vertex* prev;
  
  Vertex():label(""),distance(INT_MAX),color("WHITE"),prev(0){}
  ~Vertex(){}
};

#endif /* VERTEX_H_ */
