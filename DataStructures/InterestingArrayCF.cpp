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
#define PI acos(-1.0);
using namespace std;
typedef long long ll;
typedef vector<int> vi;

struct Node{
    Node() {value=0;}
    Node(int value):value(value){}
    int value;
};

struct SegmentTree{
    int N;
    vector<int> lazy;
    vector<Node> sTree;
    SegmentTree(int n):N(n),sTree(vector<Node>(N<<1,Node())),lazy(vector<int>(N<<1,0)){}


    Node query(int i, int j)
    {
        return query(1,1,N,i,j);
    }

    Node query(int node, int b, int e, int i, int j)	// O(log n)
    {
        if(i>e || j <b)
            return Node(-1);
        if(b>= i && e <= j)
            return sTree[node];
        propagate(node, b, e);
        Node q1 = query(node<<1,b,(b+e)/2,i,j);
        Node q2 = query((node<<1)+1,(b+e)/2+1,e,i,j);
        return Node(q1.value&q2.value);
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
            lazy[node] |= val;
            sTree[node].value |=  val;
        }
        else
        {
            propagate(node, b, e);
            update_range(node<<1,b,(b+e)/2,i,j,val);
            update_range((node<<1)+1,(b+e)/2+1,e,i,j,val);
            sTree[node].value = sTree[node<<1].value & sTree[(node<<1)+1].value;
        }

    }
    void propagate(int node, int b, int e)
    {
        lazy[node<<1] |= lazy[node];
        lazy[(node<<1)+1] |= lazy[node];
        sTree[node<<1].value |= lazy[node<<1];
        sTree[(node<<1)+1].value |= lazy[(node<<1)+1];
        lazy[node] = 0;

    }
};

struct query{
    query(){l=0,r=0,q=0;}
    query(int l,int r,int q):l(l),r(r),q(q){}
    int l,r,q;
};
int main(){
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    int N = 1; while(N < n) N <<= 1;
    SegmentTree S(N);
    int m;
    cin>>m;
    vector<query> qq;
    for (int i=0;i<m;i++) {
        int l,r,q;
        cin>>l>>r>>q;
        qq.push_back(query(l,r,q));
        S.update_range(l, r, q);
    }
    bool f = true;
    for (int i=0; i<m; i++) {
        Node res = S.query(qq[i].l, qq[i].r);
        if (res.value!=qq[i].q) {
            f=false;
            break;
        }
    }
    if (f==false) {
        cout<<"NO";
    }else{
        cout<<"YES\n";
        for (int i=0; i<n; i++) {
            cout<<S.query(i+1, i+1).value<<" ";
        }
    }

    return 0;
}
