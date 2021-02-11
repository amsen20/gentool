#include<bits/stdc++.h>

using namespace std; // TODO erase it

#ifdef USE_TESTLIB
#include "testlib.h"
#else
struct randgen{
    int next(int n){
        return rand()%n;
    }
    int wnext(int n, int t){
        if(t > 0)
            return max(next(n), wnext(n, t-1));
        if(t < 0)
            return min(next(n), wnext(n, t+1));
        return next(n);
    }
} rnd;
#endif