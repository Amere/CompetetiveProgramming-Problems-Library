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
const int mod = 1000000007;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int tC = 0;
    while (t--) {
        tC++;
        int n;
        cin>>n;
        vector<long long> v;
        for (int i=0; i<n; i++) {
            long long x;
            cin>>x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        long long res = 1;
        for (int i=0; i<n; i++) {
            res = ((res%mod)*((v[i]-i)%mod))%mod;
        }
        cout<<"Case "<<tC<<": "<<res<<endl;

    }
    return 0;
}
