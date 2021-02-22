#include "../graph.h"

using namespace std;

int main(){
    srand(time(NULL));
    WeightedGraph g(10);
    g.add_edge(0, 1);
    g.add_edge(2, 5, 6);
    g.add_edge(1, 7, 5);
    print(g);
}