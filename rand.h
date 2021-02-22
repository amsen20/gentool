#ifndef __GENTOOL_RAND_H__
#define __GENTOOL_RAND_H__

#include<bits/stdc++.h>

using namespace std; // TODO erase it

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

template<class RandomAccessIterator>
void shuffle(RandomAccessIterator begin, RandomAccessIterator end){
    random_shuffle(begin, end);
}

#endif