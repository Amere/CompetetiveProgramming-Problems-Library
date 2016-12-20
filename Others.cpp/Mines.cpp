//
//  main.cpp
//  C++Workspace
//
//  Created by Ahmed Amer on 5/30/15.
//  Copyright (c) 2015 Ahmed Amer. All rights reserved.
//
#include <map>
#include <set>
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
#include <bitset>
#define amora cout<<"amora l fshee5 :D"<<endl;
#define PI acos(-1.0);
#define INF 1000000000
#define llINF 9223372036854775807
#define EPS 1e-9
#define sz(v)        static_cast<int>((v).size())
#define pb(...)      push_back(__VA_ARGS__)
#define mp(x, y)     make_pair((x), (y))
#define clr(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, INF, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
int mod  = 1000000007;
using namespace std;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
void printV(vector<int> v){
    for (int i=0; i<v.size(); i++) {
        if (i) {
            cout<<" "<<v[i];
        }else cout<<v[i];
    }
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}
int X[3000];
int Y[3000];
int D[3000];

vector<vi> AdjList;
vector<int> vis;
vector<int> topSort;
void dfs (int u,bool f){
    if (vis[u]) {
        return ;
    }
    vis[u] = 1;
    for (int j=0; j<AdjList[u].size(); j++) {
        dfs(AdjList[u][j],f);
    }
    if (f) {
        topSort.push_back(u);
    }
}

inline int abs(int a) {
    return a>0?a:-a;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        for (int i=0; i<n; i++) {
            cin>>X[i]>>Y[i]>>D[i];
        }
        AdjList.assign(n, vi());
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (abs(X[j]-X[i])*2<=(D[i]) && abs(Y[j]-Y[i])*2<=(D[i]) && i!=j) {
                    AdjList[i].push_back(j);
                }
            }
        }
        topSort.clear();
        vis.assign(n, 0);
        int cc = 0;
        for (int i=0; i<n; i++) {
            if (!vis[i]) {
                dfs(i,1);
            }
        }
        vis.assign(n, 0);
        for (int i=(int)topSort.size()-1; i>=0; i--) {
            if (!vis[topSort[i]]) {
                cc++;
                dfs(topSort[i],0);
            }
        }
        cout<<cc<<endl;
    }
    return 0;
}
