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
using namespace std;

#define INF 1000000000
int N,M,T;
vector<double> prob;
int AdjMatrix[260][260];
vector<vector<pair<int, int>>> AdjList;

pair<double, double> memo[250+3][20000+3];

pair<double, double> solve(int u,int curT){
    if (curT>=T) {
        return make_pair(0, AdjMatrix[0][u]*prob[u]);
    }
    if (memo[u][curT].first != -1) {
        return memo[u][curT];
    }
    double p = prob[u];
    double t = p * AdjMatrix[0][u];
    for (int i=0; i<AdjList[u].size(); i++) {
        pair<int, int> v = AdjList[u][i];
        pair<double, double> res = solve(v.first, curT+v.second);
        p+=res.first;
        t+=res.second;
    }
    return memo[u][curT] = make_pair(p, t);
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int tC = 0;
    while (t--) {
        tC++;
        cin>>N>>M>>T;
        prob.assign(N+1, 0);
        for (int i=1; i<=N; i++) {
            cin>>prob[i];
        }
        AdjList.assign(N+1, vector<pair<int , int>>());
        memset(AdjMatrix, INF, sizeof(AdjMatrix));
        for (int i=0; i<M; i++) {
            int u,v,c;
            cin>>u>>v>>c;
            AdjList[u].push_back(make_pair(v, c));
            AdjList[v].push_back(make_pair(u, c));
            AdjMatrix[u][v] = c;
            AdjMatrix[v][u] = c;
        }
        for (int k = 0; k < N; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++){
                    if(AdjMatrix[i][k] + AdjMatrix[k][j]<AdjMatrix[i][j]){
                        AdjMatrix[i][j] =  AdjMatrix[i][k] + AdjMatrix[k][j];
                    }
                }
        for (int i=0; i<=250; i++) {
            for (int j=0; j<=20000; j++) {
                memo[i][j] = make_pair(-1, -1);
            }
        }
        pair<double,double> f = make_pair(0,0);
        cout<<setprecision(5);
        cout<<"Case "<<tC<<": "<<f.first<<" "<<f.second<<endl;
    }
    return 0;
}
