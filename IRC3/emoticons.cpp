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
        string s;
        cin>>s;
        int res=0,notUsed=0,half=0,com=0;
        for (int i=0; i<s.length(); i++) {
            if (s[i]=='^') {
                if (half) {
                    half--;
                    res++;
                }else{
                    if (com && res) {
                        com--;
                        half++;
                    }else{
                        notUsed++;
                    }
                }
            }else{
                if (notUsed) {
                    half++;
                    notUsed--;
                }else{
                    if (res>com) {
                        com++;
                    }
                }
            }
        }
        cout<<"Case "<<tC<<": "<<res<<endl;
    }
    return 0;
}
