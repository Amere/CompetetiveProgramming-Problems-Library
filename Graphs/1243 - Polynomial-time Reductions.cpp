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
    for (int i=1; i<v.size(); i++) {
        if (i==1) {
            cout<<" "<<v[i];
        }else cout<<v[i];
    }
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}


int AdjMatrix[200][200];
int AdjMatrixDAG[200][200];
int myComp[200];

int V,E;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int cas = 1;
    while (true) {
        clr(AdjMatrix);
        clr(AdjMatrixDAG);
        cin>>V>>E;
        int res = 0;
        if (!V&&!E) break;
        for (int i=0; i<E; i++) {
            int a,b;
            cin>>a>>b;
            a--,b--;
            AdjMatrix[a][b] = 1;
        }
        for (int k = 1; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    AdjMatrix[i][j] |= (AdjMatrix[i][k] & AdjMatrix[k][j]);
        int SCC = 0;
        clr(myComp);
        for (int i=0; i<V; i++) {
            if (myComp[i] == 0) {
                SCC++;
                myComp[i] = SCC;
                int size = 1;
                for (int j=i+1; j<V; j++) {
                    if (AdjMatrix[i][j] && AdjMatrix[j][i]) { //belong to the same comopnent
                        myComp[j] = SCC;
                        size++;
                    }
                }
                if (size>1) {
                    res+=size;
                }
            }
        }
        for (int i=0; i<V; i++) {
            for (int j=0; j<V; j++) {
                if (i==j) {
                    continue;
                }
                if (myComp[i] != myComp[j] && AdjMatrix[i][j]) {
                    AdjMatrixDAG[myComp[i]-1][myComp[j]-1] = 1;
                }
            }
        }
        for (int k = 1; k < V; k++)
            for (int i = 0; i < V; i++)
                for (int j = 0; j < V; j++)
                    AdjMatrixDAG[i][j] |= (AdjMatrixDAG[i][k] & AdjMatrixDAG[k][j]);
        for (int i=0; i<SCC; i++) {
            for (int j=0; j<SCC; j++) {
                if (i==j) {
                    continue;
                }
                if (AdjMatrixDAG[i][j]) {
                    bool path = false;
                    for (int k=0; k<SCC; k++) {
                        if (k!=j && AdjMatrixDAG[i][k] && AdjMatrixDAG[k][j]) {
                            path = true;
                            break;
                        }
                    }
                    if (!path) {
                        res++;
                    }
                }
            }
        }
        cout<<"Case "<<cas<<": "<<res<<endl;
        cas++;
    }
    return 0;
}
