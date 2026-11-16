#include "Graph.hpp"
#include <iostream>
#include <queue>

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
        std::cout << "insertVertex: vertex already exists\n";
        return;
    }

    // Add new vertex
    vertices.push_back(v);
    std::vector<int> tmp;
    adjacency_list.push_back(tmp);  // Creates empty list of neighbours for the vertex
}

template <typename T>
void Graph<T>::insertEdge(const T& v1, const T& v2) {
    // Search if vertices exist
    int i_v1 = searchVertexIndex(v1);
    int i_v2 = searchVertexIndex(v2);
    
    if (i_v1 == -1 || i_v2 == -1) {
        std::cout << "insertEdge: incorrect vertices\n";
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
    // Print the vertices
    for (int i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ": ";
        // Print all the neighbors
        for (int j : adjacency_list[i]) {
            std::cout << vertices[j] << " ";
        }
        std::cout << std::endl;
    }
    
}

template <typename T>
int Graph<T>::getDegree(const T& vertex) const {
    int index = searchVertexIndex(vertex);
    if (index == -1) {
        return -1;
    }
    return static_cast<int>(adjacency_list[index].size());
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

template <typename T>
void Graph<T>::BFS(const T& start) const {
    int start_index = searchVertexIndex(start);

    if (start_index == -1) {
        std::cout << "BFS: incorrect start vertex\n";
        return;
    }
    std::cout << "BFS: ";
    // Create a queue and the vector of discovered vertices
    std::queue<int> q;
    std::vector<bool> discovered(vertices.size(), false);

    // Add the start vertex into the queue
    q.push(start_index);
    // Mark start index discovered
    discovered[start_index] = true;

    while (!q.empty()) {
        // Get the front value from the queue
        int current_index = q.front();
        q.pop();

        std::cout << vertices[current_index] << " ";

        // Discover neighbours and add not discovered in the queue
        for (int neighbor : adjacency_list[current_index]) {
            if (!discovered[neighbor]) {
                discovered[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    std::cout << "\n";
}



template <typename T>
void Graph<T>::DFS(const T& start) const {
    int start_index = searchVertexIndex(start);

    if (start_index == -1) {
        std::cout << "DFS: incorrect start vertex\n";
        return;
    }

    std::cout << "DFS: ";
    // Create a vector of visited vertices
    std::vector<bool> visited(vertices.size(), false);
    DFSExplore(start_index, visited);
    std::cout << "\n";
}

template <typename T>
void Graph<T>::DFSExplore(int index, std::vector<bool>& visited, bool print) const {
    // Mark current index as visited
    visited[index] = true;

    if (print) {
        std::cout << vertices[index] << " ";
    }

    // Go through neighbors
    // If not visited call DFSExplore for that vertex
    for (int neighbor : adjacency_list[index]) {
        if(!visited[neighbor]) {
            DFSExplore(neighbor, visited, print);        
        }
    }
}

template <typename T>
bool Graph<T>::isConnected() const {
    // Empty graph
    if (vertices.empty()) {
        return true;
    }

    std::vector<bool> visited(vertices.size(), false);

    // Perform DFS
    DFSExplore(0, visited, false);

    for (bool v : visited) {
        if (!v) {
            return false;
        }
    }
    return true;
}

template <typename T>
int Graph<T>::shortestPath(const T& start, const T& end) const {
    int start_index = searchVertexIndex(start);
    int end_index = searchVertexIndex(end);

    if (start_index == -1 || end_index == -1) {
        std::cout << "shortestPath: incorrect vertices\n";
        return -1;
    }

    if (start == end) {
        return 0;
    }

    // Create a queue and the vector of discovered vertices
    std::queue<int> q;
    std::vector<int> distances(vertices.size(), -1);

    // Add the start vertex into the queue
    q.push(start_index);
    // Mark start index discovered
    distances[start_index] = 0;

    while (!q.empty()) {
        // Get the front value from the queue
        int current_index = q.front();
        q.pop();


        // Discover neighbours and add not discovered in the queue
        for (int neighbor : adjacency_list[current_index]) {
            if (distances[neighbor] == -1) {
                distances[neighbor] = distances[current_index] + 1;
                q.push(neighbor);

                if (neighbor == end_index) {
                    return distances[neighbor];
                }
            }
        }
    }
    
    return -1;
}