#include "../graph.h"

using namespace std;

int main(){
    srand(time(NULL));
    WeightedGraph g1(5), g2(5);
    setWeightBound(1, 10);
    auto g = concat_graphs(add_tree(g1), add_tree(g2));
    addRandomEdge(g);
    print(g);
    print(shuffle_graph(g));
}