
#include "Graph.hpp"

int main() {
    Graph<std::string> friends;

    friends.insertVertex("Ross");
    friends.insertVertex("Monica");
    friends.insertVertex("Rachel");
    friends.insertVertex("Joey");
    friends.insertVertex("Chandler");
    friends.insertVertex("Phoebe");

    // Add friendships
    friends.insertEdge("Ross", "Monica");
    friends.insertEdge("Ross", "Rachel");
    friends.insertEdge("Monica", "Chandler");
    friends.insertEdge("Joey", "Chandler");
    friends.insertEdge("Phoebe", "Rachel");

    friends.print();

    return 0;
}
