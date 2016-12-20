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
#define INF 2000000000
#define llINF 9223372036854775806
#define EPS 1e-12
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
#define cntBIT(n) __builtin_popcount(n)

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
int fixMod(int a){
    return (a % mod + mod) % mod;
}

int memo[1000+5][1000+5];
string s;
int solve(int i,int j){
    if (i>j || i==j) {
        return 0;
    }
    if (memo[i][j] !=-1) {
        return memo[i][j];
    }
    if (s[i] == s[j]) {
        return  memo[i][j] = solve(i+1,j-1);
    }
    int res1 = 1;
    int res2 = 1;
    res1+=solve(i+1, j);
    res2+=solve(i, j-1);
    return memo[i][j] = min(res1,res2);
}
int f;
string printSol(int i,int j){
    if (i>j) {
        return "";
    }
    if (s[i] == s[j]) {
        string res = toString(s[i]) + printSol(i+1, j-1);
        if (i!=j) {
            res+=toString(s[j]);
        }
        return res;
    }
    int res1 = 1;
    int res2 = 1;
    res1+=solve(i+1, j);
    res2+=solve(i, j-1);
    if (solve(i, j) == res1) {
        return toString(s[i])+printSol(i+1, j)+toString(s[i]);
    }else{
        return toString(s[j])+printSol(i, j-1)+s[j];
    }
}

int main () {
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>s) {
        f = 0;
        memset(memo, -1, sizeof(memo));
        cout<<solve(0, (int)s.length()-1)<<" "<<printSol(0, (int)s.length()-1)<<endl;
    }
    return 0;
}
