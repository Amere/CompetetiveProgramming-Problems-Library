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
    Node() {value=1;}
    Node(ll val): value(val){}
    ll value;
};
struct SegmentTree{
    ll N;
    vector<ll> array;
    vector<Node> sTree;

    SegmentTree(vector<ll> in):array(in),N((int)in.size()-1),sTree(vector<Node>(N<<1)){}
    void build(int node,int b,int e,bool xOr){
        if(b == e)
            sTree[node] = Node(array[b]);
        else
        {
            int mid = (b + e) >> 1;
            build(node<<1, b, mid,!xOr);
            build((node<<1) + 1, mid + 1, e,!xOr);
            sTree[node] = combine(sTree[node<<1], sTree[(node<<1) + 1],xOr);

        }
    }
    Node combine(Node a, Node b,bool xOr)
    {
        if(xOr){
           // cout<<a.value<<" "<<b.value<<"XOR"<<endl;
            return Node(a.value^b.value);
        }else{
           //x§ cout<<a.value<<" "<<b.value<<"OR"<<endl;
            return Node(a.value|b.value);
        }
    }
    ll update_point(int index, ll val)			// O(log n)
    {
        index += N - 1;
        sTree[index] = Node(val);
        bool xOr = 0;
        while(index>1)
        {
            index >>= 1;
            sTree[index] = combine(sTree[index<<1] , sTree[(index<<1) + 1],xOr);
            xOr=!xOr;
        }
        return sTree[1].value;
    }


};

int main(){
    std::ios::sync_with_stdio(false);
    vector<ll> v;
    ll n,q;
    cin>>n>>q;
    n = (((ll)1)<<n);
    v.push_back(1);
    for (int i=0; i<n; i++) {
        int t;
        cin>>t;
        v.push_back(t);
    }
    bool xOr = 0;
    ll check = n;
    while (check!=1) {
        check/=2;
        xOr=!xOr;
    }
    xOr=!xOr;
    SegmentTree S(v);
    S.build(1, 1, (int)v.size()-1,xOr);
    while (q--) {
        int idx,upd;
        cin>>idx>>upd;
        ll res = S.update_point(idx, upd);
        cout<<res<<endl;
    }
    return 0;
}
