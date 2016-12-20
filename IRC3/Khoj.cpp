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

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int tC = 0;
    while (t--) {
        tC++;
        int n;
        cin>>n;
        vector<string> v(n);
        string s;
        for (int i=0; i<n; i++) {
            cin>>v[i];
        }
        cin>>s;
        cout<<"Case "<<tC<<":"<<endl;
        for (int i=0; i<n; i++) {
            int d = 0;
            for (int j=0; j<s.length() ; j++) {
                if (s[j] != v[i][j]) {
                    d++;
                }
            }
            if (d<=1) {
                cout<<v[i]<<endl;
            }
        }
    }
    return 0;
}
