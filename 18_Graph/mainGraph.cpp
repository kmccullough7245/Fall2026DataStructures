
#include "Graph.hpp"
#include <string>
int main(void) {
Graph<std::string> friends;
// Insert vertices
friends.insertVertex("Ross");
friends.insertVertex("Monica");
friends.insertVertex("Rachel");
friends.insertVertex("Chandler");
friends.insertVertex("Joey");
friends.insertVertex("Phoebe");
// Create friendship
friends.insertEdge("Ross", "Rachel");
friends.insertEdge("Monica", "Chandler");
friends.insertEdge("Joey", "Chandler");
friends.insertEdge("Ross", "Chandler");
friends.insertEdge("Rachel", "Joey");
friends.BFS("Ross");
friends.DFS("Ross");
std::cout << "isConnected: " << friends.isConnected() << std::endl;
friends.insertEdge("Rachel", "Phoebe");
std::cout << "isConnected: " << friends.isConnected() << std::endl;
friends.BFS("Ross");
friends.DFS("Ross");
std::cout << "Ross to Phoebe " << friends.shortestPath("Ross", "Phoebe") <<
std::endl;
// // How many friends Chandler has
// std::cout << friends.getDegree("Chandler");
// // Are Phoebe and Joey friends
// std::cout << friends.hasEdge("Phoebe", "Joey");
return 0;
}
