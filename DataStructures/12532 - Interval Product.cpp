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
    vector<Node> sTree;

    SegmentTree(vector<int> in):array(in),N((int)in.size()-1),sTree(vector<Node>(N<<1)){}
    void build(int node,int b,int e){
        if(b == e)
            if(array[b]>0){
                sTree[node] = Node('+');
            }else{
                if(array[b]<0){
                    sTree[node]=Node('-');
                }else{
                    sTree[node]=Node('0');
                }
            }
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
      //  cout<<a.value<<"  "<<b.value<<endl;;
        if(a.value=='0'||b.value=='0'){
            return Node('0');
        }else{
            if((a.value=='+'&&b.value=='+')||(a.value=='-'&&b.value=='-')){
                return Node('+');
            }else{

                return Node('-');
            }
        }
    }
    void update_point(int index, int val)			// O(log n)
    {
        index += N - 1;
       // cout<<"Hereee"<<sTree[index].value<<"Hereee"<<index<<endl;
        if(val>0){
            sTree[index] = Node('+');
        }else{
            if(val<0){
                sTree[index] = Node('-');
            }else{
                sTree[index] = Node('0');
            }
        }
        while(index>1)
        {
            index >>= 1;
            sTree[index] = combine(sTree[index<<1] , sTree[(index<<1) + 1]);
        }
    }

    Node query(int i, int j)
    {
        return query(1,1,N,i,j);
    }

    Node query(int node, int b, int e, int i, int j)	// O(log n)
    {
        if(i>e || j <b)
            return Node('+');
        if(b>= i && e <= j)
            return sTree[node];
        Node q1 = query(node<<1,b,(b+e)/2,i,j);
        Node q2 = query((node<<1)+1,(b+e)/2+1,e,i,j);
        return combine(q1 , q2);
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    int n,q;
    while (cin>>n>>q) {
    int N = 1; while(N < n) N <<= 1;
    vector<int> v(N+1,1);
    for (int i=1; i<=n; i++) {
        cin>>v[i];
    }
    SegmentTree S(v);
    S.build(1, 1, (int)v.size()-1);
    while (q--) {
        char m;
        cin>>m;
        if(m=='C'){
            int idx,upd;
            cin>>idx>>upd;
            S.update_point(idx, upd);
        }else{
            int i,j;
            cin>>i>>j;
            Node res;
            res = S.query(i, j);
            cout<<res.value;
        }
    }
        cout<<endl;
    }
    return 0;
}
