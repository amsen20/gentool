#include "../graph.h"

using namespace std;

int main(){
    srand(time(NULL));
    WeightedGraph g1(5), g2(5);
    setWeightBound(1, 10);
    auto g = concat_graphs(add_tree(g1), add_tree(g2));
    addRandomEdge(g);
    print(g);
    vector<int> perm;
    print(shuffle_graph(g, perm));
    for(int i=0 ; i<perm.size() ; i++)
        cout << i+1 << " => " << perm[i]+1 << "\n";
}