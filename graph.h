#include "rand.h"
#include<bits/stdc++.h>

using namespace std; // TODO erase it

template<typename Ed>
struct graph{

    typedef pair<int, Ed*> ie;

    int n, m;
    vector<vector<ie> > g; // TODO add matrix
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
        sg = vector<set<ie> >(n, set<ie>());
        for(int i=0 ; i<n ; i++){
            sg.push_back(set<int>());
            sg[i].clear();
            for(auto J : g[i]){
                int j = J.first;
                sg[i].insert(j);
            }
        }
    }

    graph():
        n(-1), m(-1) {
            g = vector<vector<ie> >();
        }
    
    ~graph(){
        for(int i=0 ; i<n ; i++)
            for(auto U : g[i]){
                int u = U.first;
                if(i < u) // TODO take care of directed graphs
                    delete U.second;
            }
    }

    graph(int n):
        n(n){
            m = 0;
            g = vector<vector<ie> >(n, vector<ie>());
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

    bool custom_add_edge(int v, int u, Ed *e){ // TODO take care of direcred graphs
        if(!SL && v == u)
            return false;
        if(SEE){
            if(!ME && (sg[v].count(u) || sg[u].count(v)))
                return false;
            sg[v].insert(u);
            sg[u].insert(v);
        }
        m ++;
        g[v].push_back(ie(u, e));
        g[u].push_back(ie(v, e));
        return true;
    }

    bool add_edge(int v, int u){
        return custom_add_edge(v, u, new Ed(v, u));
    }

    vector<Ed> get_edges() const { // TODO take care of directed graphs
        set<Ed> st;
        for(int i=0 ; i<n ; i++)
            for(auto j : g[i])
                if(!st.count(*j.second))
                    st.insert(*j.second);
        vector<Ed> ret;
        for(auto i : st)
            ret.push_back(i);
        return ret;
    }
};

// simple graph
typedef graph<pair<int, int> > SimpleGraph;

template<typename Ed>
Ed *default_edge_generator(int v, int u){
    return new Ed(v, u);
}

/*
    * pure function
    * O(n) (or O(nlgn) if SSE)
    * t: how near to star should be tree. (100 star, -100 path)
*/
template<typename Ed>
graph<Ed> add_tree(
    const graph<Ed> &gr,
    int t=0,
    function<Ed*(int v, int u)> edge_generator=default_edge_generator
    ){
    graph<Ed> ret = gr;
    for(int i=1 ; i<gr.n ; i++){
        int to = rnd.wnext(i, t);
        ret.custom_add_edge(to, i, edge_generator(to, i));
    }
    return ret;
}

template<typename Ed>
bool add_random_simple_edge(
    graph<Ed> &gr,
    function<Ed*(int v, int u)> edge_generator=default_edge_generator
    ){
    // TODO check if edges are a lot use another method
    int v, u;
    do{
        v = rnd.next(gr.n);
        u = rnd.next(gr.n);
    }while(!gr.custom_add_edge(v, u, edge_generator(v, u)));
    return true;
}

void print(const SimpleGraph& gr){
    cout << gr.n << " " << gr.m << "\n";
    for(auto i : gr.get_edges())
        cout << i.first+1 << " " << i.second+1 << "\n";
}