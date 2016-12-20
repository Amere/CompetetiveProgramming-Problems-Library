//
//  main.cpp
//  Practice2
//
//  Created by Ahmed Amer on 12/14/16.
//  Copyright © 2016 Ahmed Amer. All rights reserved.
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
#define INF 2000000000
#define llINF 10000000000000000ll
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
#define cntBIT(n) __builtin_popcount(n)
#define NOT(x)    (1^(x))
#define toLowerCase(s)  transform(s.begin(),s.end(),s.begin(),::tolower)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
void printV(vector<ll> v){
    for (int i=0; i<v.size(); i++) {
        if (i) {
            cout<<" "<<v[i];
        }else cout<<v[i];
    }
    cout<<endl;
}

int memo[6101][6101];
string s;
int solve(int i,int j){
    if (i >= j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }
    if (s[i] == s[j]) {
        return memo[i][j] = solve(i+1, j-1);
    }
    int right = 1 + solve(i+1, j);
    int left = 1 + solve(i, j-1);
    return memo[i][j] = min(left,right);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while (t--) {
        cin>>s;
        memset(memo, -1, sizeof(memo));
        cout<<solve(0, (int)s.length()-1)<<endl;;
    }
    return 0;
}
