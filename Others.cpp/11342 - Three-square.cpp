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

#define MAX 50006

int arr[MAX][4];
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    clr(arr);
    for (int i=0; i*i<MAX; i++) {
        for (int j=0; j*j<MAX; j++) {
            for (int k=0; k*k<MAX; k++) {
                int cur = i*i + j*j + k*k;
                if (cur>MAX || arr[cur][3]) {
                    continue;
                }
                arr[cur][0] = i;
                arr[cur][1] = j;
                arr[cur][2] = k;
                arr[cur][3] = 1;
            }
        }
    }

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        if (!arr[n][3]) {
            cout<<-1<<endl;
        }else{
            sort(arr[n], arr[n]+3);
            cout<<arr[n][0]<<" "<<arr[n][1]<<" "<<arr[n][2]<<endl;
        }
    }

    return 0;
}
