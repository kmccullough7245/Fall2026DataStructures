
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <string>

template <typename T>
class Graph {
public:
    void insertVertex(const T& v);
    void insertEdge(const T& v1, const T& v2);
    void print() const;
    int getDegree(const T& vertex) const;
    bool hasEdge(const T& v1, const T& v2) const;

private:
    std::vector<T> vertices;
    std::vector<std::vector<int>> adjacency_list;

    int searchVertexIndex(const T& value) const;
};

#include "Graph.cpp"

#endif
