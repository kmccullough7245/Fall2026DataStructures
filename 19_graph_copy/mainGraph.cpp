
#include "Graph.hpp"
#include <string>
int main(void) {
Graph<std::string> cities;
// Insert vertices
cities.insertVertex("Tampa");
cities.insertVertex("Lakeland");
cities.insertVertex("Orlando");
cities.insertVertex("Naples");
cities.insertVertex("Miami");
// Create friendship
cities.insertEdge("Tampa", "Lakeland", 40);
cities.insertEdge("Lakeland", "Orlando", 50);
cities.insertEdge("Orlando", "Miami", 200);
cities.insertEdge("Lakeland", "Miami", 350);
cities.insertEdge("Tampa", "Naples", 185);
cities.insertEdge("Naples", "Miami", 150);
cities.insertEdge("Tampa", "Miami", 500);

cities.print();

return 0;
}
