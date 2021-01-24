#include "rand.h"
#include<bits/stdc++.h>

using namespace std; // TODO erase it

struct graph{ // TODO use template for edges
    int n, m;
    vector<vector<int> > g; // TODO add matrix
    vector<set<int> > sg;
    /*
        * can be turned it off
        * Store Edges Efficient
    */
    bool SEE = true;
    /*
        * can have Self Loop
    */
    bool SL = false;
    /*
        * can have Multiple Edges
    */
    bool ME = false;

    void build_sg(){
        assert(SEE);
        sg = vector<set<int> >(n, set<int>());
        for(int i=0 ; i<n ; i++){
            sg.push_back(set<int>());
            sg[i].clear();
            for(auto j : g[i])
                sg[i].insert(j);
        }
    }

    graph():
        n(-1), m(-1) {
            g = vector<vector<int> >();
        }
    graph(int n, int m):
        n(n), m(m) {
            g = vector<vector<int> >(n, vector<int>());
            sg = vector<set<int> >(n, set<int>());
        }
    graph(const graph &other){
        n = other.n;
        m = other.m;
        g = other.g;
        SEE = other.SEE;
        SL = other.SL;
        ME = other.ME;
        if(SEE)
            build_sg();
    }
    bool add_edge(int v, int u){ // TODO use template for edges
        if(!SL && v == u)
            return false;
        if(SEE){
            if(!ME && (sg[v].count(u) || sg[u].count(v)))
                return false;
            sg[v].insert(u);
            sg[u].insert(v);
        }
        m ++;
        g[v].push_back(u);
        g[u].push_back(v);
        return true;
    }
    vector<pair<int, int> > get_edges() const { // TODO use template for edges
        set<pair<int, int> > st;
        for(int i=0 ; i<n ; i++)
            for(auto j : g[i])
                if(!st.count({j, i}))
                    st.insert({i, j});
        vector<pair<int, int> > ret;
        for(auto i : st)
            ret.push_back({i.first, i.second});
        return ret;
    }
};

/*
    * pure function
    * O(n) (or O(nlgn) if SSE)
    * t: how near to star should be tree. (100 star, -100 path)
*/
graph add_tree(const graph &gr, int t=0){
    graph ret = gr;
    for(int i=1 ; i<gr.n ; i++){
        int to = rnd.wnext(i, t);
        ret.add_edge(to, i);
    }
    return ret;
}

bool add_random_simple_edge(graph &gr){
    // TODO check if edges are a lot use another method
    int v, u;
    do{
        v = rnd.next(gr.n);
        u = rnd.next(gr.n);
    }while(!gr.add_edge(v, u));
    return true;
}

void print_graph(const graph& gr){
    cout << gr.n << " " << gr.m << "\n";
    for(auto i : gr.get_edges())
        cout << i.first+1 << " " << i.second+1 << "\n";
}