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
    Node() {value=0;}
    Node(int val): value(val){}
    int value;
};




struct SegmentTree{
    int N;
    vector<int> array;
    vector<Node> sTree;

    SegmentTree(vector<int> in):array(in),N((int)in.size()-1),sTree(vector<Node>(N<<1)){}
    void build(int node,int b,int e){
        if(b == e)
            sTree[node] = Node(array[b]);
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
        return Node(a.value+b.value);
    }
    void update_point(int index, int val)			// O(log n)
    {
        index += N - 1;
        sTree[index] = Node(val);
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
            return Node(0);
        if(b>= i && e <= j)
            return sTree[node];
        Node q1 = query(node<<1,b,(b+e)/2,i,j);
        Node q2 = query((node<<1)+1,(b+e)/2+1,e,i,j);
        return combine(q1 , q2);

    }
};

int main(){
    int cc = 0;
    while (true) {
        cc++;
        int n;
        cin>>n;
        if (n==0) {
            break;
        }
        if (cc!=1) {
            cout<<endl;
        }
        cout<<"Case "<<cc<<":"<<endl;
        int N = 1; while(N < n) N <<= 1;
        vector<int> v(N+1);
        for (int i=1; i<=n; i++) {
            cin>>v[i];
        }
        SegmentTree S(v);
        S.build(1, 1, (int)v.size()-1);
        while (true) {
            string c;
            cin>>c;
            if (c=="END") {
                break;
            }
            int i,j;
            cin>>i>>j;
            if (c=="M") {
                int res = S.query(i, j).value;
                cout<<res<<endl;
            }else{
                S.update_point(i, j);
            }
        }
    }
    return 0;
}
