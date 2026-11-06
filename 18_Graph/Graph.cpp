
#ifndef GRAPH_CPP
#define GRAPH_CPP

#include "Graph.hpp"

template <typename T>
int Graph<T>::searchVertexIndex(const T& value) const {
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == value) {
            return i;
        }
    }
    return -1;
}

template <typename T>
void Graph<T>::insertVertex(const T& v) {
    // Check for duplicates
    if (searchVertexIndex(v) != -1) {
        std::cout << "Vertex already exists." << std::endl;
        return;
    }

    // Add vertex to the list
    vertices.push_back(v);

    std::vector<int> tmp;
    adjacency_list.push_back(tmp);
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2) {
    // Search if vertices exist
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);

    if (i_v1 == -1 || i_v2 == -1) {
        std::cout << "One or both vertices do not exist." << std::endl;
        return;
    }

    // Avoid duplicate edges
    for (int neighbor : adjacency_list[i_v1]) {
        if (neighbor == i_v2) {
            return;
        }
    }

    // Insert in the adjacency list
    adjacency_list[i_v1].push_back(i_v2);
    adjacency_list[i_v2].push_back(i_v1);
}

template <typename T>
void Graph<T>::print() const {
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";

        for (int neighbor : adjacency_list[i]) {
            std::cout << vertices[neighbor] << " ";
        }

        std::cout << std::endl;
    }
}

template <typename T>
int Graph<T>::getDegree(const T& vertex) const {
    int index = searchVertexIndex(vertex);
    if (index == -1) {
        return 0;
    }
    return adjacency_list[index].size();
}

template <typename T>
bool Graph<T>::hasEdge(const T& v1, const T& v2) const {
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);

    if (i_v1 == -1 || i_v2 == -1) {
        return false;
    }

    for (int neighbor : adjacency_list[i_v1]) {
        if (neighbor == i_v2) {
            return true;
        }
    }

    return false;
}

#endif
