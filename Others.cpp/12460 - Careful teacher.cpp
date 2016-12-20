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

int commonS(string s,string s1){
    int count = 0;
    for (int i=0; i<s.length(); i++) {
        for (int j=0; j<s1.length(); j++) {
            if (s[i]==s1[j]) {
                s1[j] = '-';
                count++;
                break;
            }
        }
    }
    return count;
}
string q,q1;
int des;
bool res;
vector<vi> AdjList;
vi dfs_num;
void dfs(int u){
    if (u==des) {
        res = true;
    }
    dfs_num[u] = DFS_BLACK;
    for (int i=0;  i < (int)AdjList[u].size(); i++) {
        int child = AdjList[u][i];
        if (dfs_num[child]==DFS_WHITE)
            dfs(child);
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    vector<string> vs;
    map<string,int> m;
    while (cin>>s) {
        if (s=="--") {
            break;
        }
        vs.pb(s);
    }
    REP(i, 0, sz(vs)){
        m[vs[i]] = i;
    }
    AdjList.assign(sz(vs),vi());
    REP(i, 0, sz(vs)){
        REP(j, i+1, sz(vs)){
            if (vs[i].length() == vs[j].length()) {
                if (commonS(vs[i], vs[j]) == vs[i].length()-1) {
                    AdjList[i].push_back(j);
                    AdjList[j].push_back(i);
                }
            }
        }
    }
    while (cin>>q>>q1) {
        res = false;
        int source = m[q];
        des = m[q1];
        dfs_num.assign(sz(vs), DFS_WHITE);
        dfs(source);
        if (res) {
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<endl;
    }
    return 0;
}
