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
#define cntBIT(n) __builtin_popcount(n)
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


ll memo[6101][2],n;
vi mon;

ll solve(int i,bool t){
    if (i == n) {
        return 0;
    }
    if (memo[i][t]!=-1) {
        return memo[i][t];
    }
    if (t) {
        return memo[i][t] = solve(i+1, 0);
    }
    return memo[i][t] = max(mon[i] + solve(i+1, 1),solve(i+1, 0));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int tC = 0;
    while (t--) {
        cin>>n;
        mon.clear();
        for (int i = 0; i < n; i++) {
            int c;
            cin>>c;
            mon.pb(c);
        }
        memset(memo, -1, sizeof(memo));
        cout<<"Case "<<++tC<<": "<<solve(0, 0)<<endl;;
    }
    return 0;
}
