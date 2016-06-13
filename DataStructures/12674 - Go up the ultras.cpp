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
    Node() {height=0;}
    Node(int height):height(height){}
    int height;
};

struct SegmentTree{
    int N;
    vector<int> array;
    vector<Node> sTree;
    SegmentTree(vector<int> in):array(in),N((int)in.size()-1),sTree(vector<Node>(N<<1,1000000000)){}

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
        return min(a.height,b.height);
    }

    int query(int i, int j)
    {
        return query(1,1,N,i,j);
    }

    int query(int node, int b, int e, int i, int j)	// O(log n)
    {
        if(i>e || j <b)
            return 1000000000;
        if(b>= i && e <= j)
            return sTree[node].height;
        int q1 = query(node<<1,b,(b+e)/2,i,j);
        int q2 = query((node<<1)+1,(b+e)/2+1,e,i,j);
        return min(q1,q2);
    }
};
    struct peak{
        peak() {height=0,idx=0;}
        peak(int height,int idx):height(height), idx(idx){}
        int height;
        int idx;
    };

    bool cmp(peak a,peak b){
        return a.idx<b.idx;
    }

int main(){
    ios_base::sync_with_stdio(0);

    int n;
    while (cin>>n) {
        vector<peak> peaks;
        vector<int> v(n);
        for (int i=0; i<n; i++) {
            cin>>v[i];
        }
        for (int i=0; i<n-2; i++) {
            if (v[i+1]>v[i]&&v[i+1]>v[i+2]) {
                peaks.push_back(peak(v[i+1],i+1));
            }
        }
        int N = 1; while(N < n) N <<= 1;
        vector<int> vv(N+1,1000000000);
        for (int i=0; i<n; i++)
            vv[i+1] = v[i];
        SegmentTree S(vv);
        S.build(1, 1, (int)vv.size()-1);

        int rightP[n];
        int leftP[n];
        leftP[peaks[0].idx] = -1;
        stack<peak> left;
        left.push(peaks[0]);
        for (int i=1; i<peaks.size(); i++) {
            while (!left.empty()&&left.top().height<=peaks[i].height) {
                left.pop();
            }
            if (left.empty()) {
                leftP[peaks[i].idx] = -1;
            }else{
                leftP[peaks[i].idx] = left.top().idx;
            }
            left.push(peaks[i]);
        }
        stack<peak> right;
        right.push(peaks[peaks.size()-1]);
        rightP[peaks[peaks.size()-1].idx] = -1;
        for (int i=(int)peaks.size()-2; i>=0; i--) {
            while (!right.empty()&&right.top().height<=peaks[i].height) {
                right.pop();
            }
            if (right.empty()) {
                rightP[peaks[i].idx] = -1;
            }else{
                rightP[peaks[i].idx] = right.top().idx;
            }
            right.push(peaks[i]);
        }


        vector<peak> results;
        for (int i=0; i<peaks.size(); i++) {
            if (leftP[peaks[i].idx]==-1) {
                if (rightP[peaks[i].idx]==-1) {
                    if (peaks[i].height>=150000) {
                        results.push_back(peaks[i]);
                    }
                }else{
                    int lowest = S.query(peaks[i].idx+2, rightP[peaks[i].idx]);
                    if(peaks[i].height-lowest>=150000){
                        results.push_back(peaks[i]);
                    }
                }
            }else{
                if(rightP[peaks[i].idx]==-1){
                    int lowest = S.query(leftP[peaks[i].idx]+2, peaks[i].idx);
                    if(peaks[i].height-lowest>=150000){
                        results.push_back(peaks[i]);
                    }
                }else{
                    int lowest = max(S.query(peaks[i].idx+2, rightP[peaks[i].idx]),S.query(leftP[peaks[i].idx]+2, peaks[i].idx));

                    if(peaks[i].height-lowest>=150000){
                        results.push_back(peaks[i]);
                    }
                }
            }
        }
        /*
        Graph test case DEBUGGING
        26
        0 500000 1500000 2000000 1500000 2000000 3000000 1000000 500000 1500000 3250000 3500000 2500000 3500000 2000000 2250000 3000000 500000 1000000 2500000 1000000 1500000 5000000 3000000 2500000 0
        */
        sort(results.begin(), results.end(), cmp);
        for (int i=0; i<results.size(); i++) {
            if(i){
                cout<<" "<<results[i].idx+1;
            }else{
                cout<<results[i].idx+1;
            }
        }
        cout<<endl;
    }
    return 0;
}
