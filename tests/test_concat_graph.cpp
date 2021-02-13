#include "../graph.h"

using namespace std;

int main(){
    srand(time(NULL));
    SimpleGraph g1(10), g2(5);
    auto g = concat_graphs(add_tree(g1), add_tree(g2));
    addRandomEdge(g);
    print(g);
}