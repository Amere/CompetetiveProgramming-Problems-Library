#include <map>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <sstream>
#include <fstream>
#include <iomanip>
using namespace std;
typedef long long ll;

struct Node{
    Node() {value='+';}
    Node(char val): value(val){}
    char value;
};




struct SegmentTree{
    int N;
    vector<int> array;
    vector<Node> sTree,lazy;

    SegmentTree(vector<int> in):array(in),N((int)in.size()-1),sTree(vector<Node>(N<<1)),lazy(vector<Node>(N<<1)){}
    void build(int node,int b,int e){
        if(b == e)
            sTree[node] = Node(array[b],1);
        else
        {
            int mid = (b + e) >> 1;
            build(node<<1, b, mid);
            build((node<<1) + 1, mid + 1, e);
            sTree[node] = combine(sTree[node<<1], sTree[(node<<1) + 1]);
        }
    }
    Node combine(Node a, Node b)
    {
        if(a.max > b.max)
            return Node(a.max, a.freq);
        else if(a.max < b.max)
            return Node(b.max, b.freq);
        return Node(a.max, a.freq + b.freq);
    }
    void update_point(int index, int val)			// O(log n)
    {
        index += N - 1;
        sTree[index] = Node(val,1);
        while(index>1)
        {
            index >>= 1;
            sTree[index] = combine(sTree[index<<1] , sTree[(index<<1) + 1]);
        }
    }
    void update_range(int i, int j, int val)		// O(log n)
    {
        update_range(1,1,N,i,j,val);
    }

    void update_range(int node, int b, int e, int i, int j, int val)
    {
        if(i > e || j < b)
            return;
        if(b >= i && e <= j)
        {
            sTree[node].freq = (e-b+1);
            sTree[node].max = (val);
            lazy[node].max = val;
            lazy[node].freq = (e-b+1)/2;
        }
        else
        {
            propagate(node, b, e);
            update_range(node<<1,b,(b+e)/2,i,j,val);
            update_range((node<<1)+1,(b+e)/2+1,e,i,j,val);
            sTree[node] = combine(sTree[node<<1] , sTree[(node<<1)+1]);
        }

    }
    void propagate(int node, int b, int e)
    {
        int mid = (b+e)/2;
        lazy[node<<1].max = lazy[node].max;
        lazy[(node<<1)+1].freq = (e-b+1)/2;
        sTree[node<<1].max += (mid-b+1)*lazy[node];
        sTree[(node<<1)+1] += (e-mid)*lazy[node];
        lazy[node].freq = 0;
        lazy[node].freq = -INF;

    }

    Node query(int i, int j)
    {
        return query(1,1,N,i,j);
    }

    Node query(int node, int b, int e, int i, int j)	// O(log n)
    {
        if(i>e || j <b)
            return Node(-100000000,0);
        if(b>= i && e <= j)
            return sTree[node];
        propagate(node, b, e);
        Node q1 = query(node<<1,b,(b+e)/2,i,j);
        Node q2 = query((node<<1)+1,(b+e)/2+1,e,i,j);
        return combine(q1 , q2);

    }
};

int main(){
    int N = 1; while(N < n) N <<= 1;
    vector<int> v(N+1);
    SegmentTree S(v);
    S.build(1, 1, (int)v.size()-1);

    return 0;
}
