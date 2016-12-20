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

int back[1000000];
string p,t;
vi res;
int n;
void kmpPreprocess(){
    int i = 0,j = -1;
    back[0] = -1;
    while (i < n) {
        while (j >=0 && p[i] != p[j]) {
            j = back[j];
        }
        i++,j++;
        back[i] = j;
    }
}
void kmpSearch(){
    res.clear();
    int i = 0, j = 0;
    while (i < t.length()) {
        while (j >= 0 && t[i] != p[j]) {
            j = back[j];
        }
        i++,j++;
        if (j == n) {
            res.pb(i - j);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>n) {
        cin>>p>>t;
        kmpPreprocess();
        kmpSearch();
        if (!res.size()) {
            cout<<endl<<endl;
        }
        for (int i = 0; i < res.size(); i++) {
            cout<<res[i]<<endl;;
        }
    }
    return 0;
}
