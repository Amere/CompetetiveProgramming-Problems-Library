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

int grid[15+3][15+3];
int mini;
int n;
void press(int x,int y){
    grid[x][y] = 1-grid[x][y];
}
bool valid(int x,int y){
    return x<n && x>=0 && y<n && y>=0;
}
bool check(int x,int y){
    int count = 0;
    if (valid(x-1,y)) {
        count+=grid[x-1][y];
    }
    if (valid(x,y-1)) {
        count+=grid[x][y-1];
    }
    if (valid(x+1,y)) {
        count+=grid[x+1][y];
    }
    if (valid(x,y+1)) {
        count+=grid[x][y+1];
    }
    return count&1;
}
void backtrack(int x,int y,int count){
    if (y==n) {
        x++;
        y=0;
    }
    if (x==0) {
        backtrack(x, y+1, count);
        if (grid[x][y]==0) {
            press(x, y);
            backtrack(x, y+1, count+1);
            press(x, y);
        }
        return;
    }
    if (x<n) {
        if(check(x-1, y)) {
            if(grid[x][y] == 0) {
                press(x, y);
                backtrack(x, y+1, count+1);
                press(x, y);
            }
        } else {
            backtrack(x, y+1, count);
        }
        return;
    }
    for (int i=0; i<n; i++) {
        if (check(n-1, i)) {
            return;
        }
    }
    mini = min(mini,count);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int tC = 0;
    while (t--) {
        tC++;
        mini = INF;
        cin>>n;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                cin>>grid[i][j];
            }
        }
        backtrack(0, 0, 0);
        if (mini == INF) {
            mini =-1;
        }
        cout<<"Case "<<tC<<": "<<mini<<endl;
    }
    return 0;
}
