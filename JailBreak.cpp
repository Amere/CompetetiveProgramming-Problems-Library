//
//  main.cpp
//  C++Workspace
//
//  Created by Ahmed Amer on 5/30/15.
//  Copyright (c) 2015 Ahmed Amer. All rights reserved.
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
#define rep(i, v) for(int i=0;i<sz(v);++i)
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
typedef vector<vi> matrix;
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
int n,m;
int grid[100+5][100+5];
int memo[100+5][100+5][2][7][2];

int valid(int i,int j){
    if (i >= 0 && i<n && j>=0 && j<m) {
        if (grid[i][j]) {
            return 1;
        }else{
            return 0;
        }
    }
    return 0;
}
int curX,curY;
int solve(int i,int j,int cnt,int dir,int c){
    if ((i==0 || i==n-1 || j==0 || j==m-1)&&cnt) {
        return 0;
    }
    if (memo[i][j][cnt][dir][c]!=-1) {
        return memo[i][j][cnt][dir][c];
    }
    if (grid[i][j] == 2 && !(i==curX && j==curY)) {
        cnt = 1;
        c = 1;
    }else{
        c=0;
    }
    int res = INF;
    if (valid(i+1,j) && (dir!=1 || c)) {
        if (grid[i+1][j] == 1) {
            res = min(res, 1+solve(i+1, j, cnt,4,c));
        }else{
            cout<<"here"<<endl;

            res = min(res, solve(i+1, j, cnt,4,c));
        }
    }
    if (valid(i,j+1) && (dir!=2 || c)) {
        if (grid[i][j+1] == 1) {
            res = min(res, 1+solve(i, j+1, cnt,3,c));
        }else{
            cout<<"here"<<endl;

            res = min(res, solve(i, j+1, cnt,3,c));
        }
    }
    if (valid(i-1,j) && (dir!=4 || c)) {
        if (grid[i-1][j] == 1) {
            res = min(res, 1+solve(i-1, j, cnt,1,c));
        }else{
            cout<<"here"<<endl;

            res = min(res, solve(i-1, j, cnt,1,c));
        }
    }
    if (valid(i,j-1) && (dir!=3 || c)) {
        if (grid[i][j-1] == 1) {
            res = min(res, 1+solve(i, j-1, cnt,2,c));
        }else{
            cout<<"here"<<endl;
            res = min(res, solve(i, j-1, cnt,2,c));
        }
    }
    cout<<res<<endl;
    return memo[i][j][cnt][dir][c] = res;
}

int main () {
    int t;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        int x =-1 ,y = -1,x1 =-1 ,y1 =-1;
        for (int i=0; i<n; i++) {
            string s;
            cin>>s;
            for (int j=0; j<s.length(); j++) {
                if (s[j] == '*') {
                    grid[i][j] = 0;
                }else{
                    if (s[j]=='#') {
                        grid[i][j] = 1;
                    }else{
                        if (s[j] == '$') {
                            if (x==-1) {
                                x = i;
                                y = j;
                            }else{
                                x1 = i;
                                y1 = j;
                            }
                            grid[i][j] = 2;
                        }else{
                            grid[i][j] = 3;
                        }
                    }
                }
            }
        }
        memset(memo, -1, sizeof(memo));
        curX = x;
        curY = y;
        int res1 = solve(x,y,0,0,0);
        cout<<"dif\n";
        curX = x1;
        curY = y1;
        memset(memo, -1, sizeof(memo));
        int res2 = solve(x1,y1,0,0,0);
        cout<<min(res1,res2)<<endl;;

    }
    return 0;
}
