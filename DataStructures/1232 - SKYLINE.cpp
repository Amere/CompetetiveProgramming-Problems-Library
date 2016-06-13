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
    Node() {minHeight=0,maxHeight=0;}
    Node(int height_,int maxHeight): minHeight(height_),maxHeight(maxHeight){}
    int maxHeight,minHeight;
};


struct SegmentTree{
    int N;
    vector<Node> sTree;
    vector<int> lazy;

    SegmentTree(vector<int> in):N((int)in.size()-1),sTree(vector<Node>(N<<1,Node(0,0))),lazy(vector<int>(N<<1,0)){}

    inline void update_range(int i, int j, int val)		// O(log n)
    {
        return update_range(1,1,N,i,j,val);
    }

    inline void update_range(int node, int b, int e, int i, int j, int val)
    {

        if(i > e || j < b)
            return;
        if(e==b){
            if(sTree[node].maxHeight<val){
                sTree[node].maxHeight = val;
                sTree[node].minHeight = val;
                return;
            }else{
                return;
            }
        }
        if(val<=sTree[node].minHeight)
            return;
        if(i<=b&&j>=e){
            lazy[node]=max(lazy[node], val);
            sTree[node].minHeight = max(sTree[node].minHeight,lazy[node]);
            sTree[node].maxHeight=max(val, sTree[node].maxHeight);
            return;
        }
            propagate(node, b, e);
            update_range(node<<1,b,(b+e)/2,i,j,val);
            update_range((node<<1)+1,(b+e)/2+1,e,i,j,val);
            sTree[node].maxHeight = max(sTree[node<<1].maxHeight , sTree[(node<<1)+1].maxHeight);
            sTree[node].minHeight = min(sTree[node<<1].minHeight , sTree[(node<<1)+1].minHeight);

    }
    inline void propagate(int node, int b, int e)
    {
        lazy[node<<1] = max(lazy[node],lazy[node<<1]);
        lazy[(node<<1)+1] = max(lazy[node],lazy[(node<<1)+1]);
        sTree[node<<1].maxHeight = max(lazy[node<<1],sTree[node<<1].maxHeight);
        sTree[(node<<1)+1].maxHeight = max(lazy[(node<<1)+1],sTree[(node<<1)+1].maxHeight);
        sTree[node<<1].minHeight = max(lazy[node<<1],sTree[node<<1].minHeight);
        sTree[(node<<1)+1].minHeight = max(lazy[(node<<1)+1],sTree[(node<<1)+1].minHeight);
    }
    inline int query(int i, int j,int h)
    {
        return query(1,1,N,i,j, h);
    }

    inline int query(int node, int b, int e, int i, int j,int h)	// O(log n)
    {
        if(i>e || j<b)
            return 0;

        if(b==e){
            if(sTree[node].maxHeight<=h){
                return 1;
            }else{
                return 0;
            }
        }
        if(h<sTree[node].minHeight){
            return 0;
        }

        if((b>= i && e <= j)){
            if((h>=sTree[node].maxHeight))
                return e-b+1;
            else
                if(h<lazy[node])
                    return 0;
        }
        propagate(node, b, e);
        int q1 = query(node<<1,b,(b+e)/2,i,j,h);
        int q2 = query((node<<1)+1,(b+e)/2+1,e,i,j,h);
        return q1+q2;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--) {
        int q;
        cin>>q;
        vector<pair<int,pair<int, int>>> v;
        int maxR=-1000000001,minL=1000000001;
        for (int i=0; i<q; i++) {
            int s,ss,sss;
            cin>>s>>ss>>sss;
            if (s<minL) {
                minL = s;
            }
            if (ss>maxR) {
                maxR=ss;
            }
            v.push_back(make_pair(s, make_pair(ss, sss)));
        }
        minL--;
        maxR-=minL;
        for (int i=0; i<q; i++) {
            v[i].first-=minL;
            v[i].second.first-=minL;
        }
        int N = 1; while(N < maxR) N <<= 1;
        vector<int> v1(N+1);
        SegmentTree S(v1);
        int res = 0;
        for (int i=0; i<q; i++) {
            res+=S.query(v[i].first, v[i].second.first-1, v[i].second.second);
            S.update_range(v[i].first, v[i].second.first-1, v[i].second.second);
        }
        cout<<res<<endl;
    }
    cin>>t;
    return 0;
}
