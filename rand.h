#include<bits/stdc++.h>

#ifdef USE_TESTLIB
// TODO use testlib here
#else
struct randgen{
    int next(int n){
        return rand()%n;
    }
} rnd;
#endif