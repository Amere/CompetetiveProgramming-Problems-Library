#include <set>
#include <map>
#include <list>
#include <bitset>
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
#define pi acos(-1.0)
using namespace std;
int n;
int negInf = -10e9;
vector<int> v;

int main() {
    // freopen("crosses.in" , "r", stdin);
    // freopen("crosses.out", "w", stdout);
    int ss=0;
    bool last = false;
    int prev;
    cin>>prev;
    while (true) {
        ss++;
        n=1;
        v.clear();
        int temp;
        v.push_back(prev);
        while (true) {
            cin>>temp;
            if (temp==-1) {
                break;
            }
            v.push_back(temp);
            n++;
        }
        cin>>prev;
        if (prev==-1) {
            last = true;
        }
        int arr[n];
        for (int i=0; i<n; i++) {
            arr[i]=1;
        }
        int res = negInf;
        for (int i=1; i<n; i++) {
            for (int j=0; j<i; j++) {
                if (v[j]>=v[i]) {
                    arr[i] = max(arr[i],arr[j]+1);
                }
            }
            res = max(arr[i],res);
        }
        res = max(1,res);
        cout<<"Test #"<<ss<<":"<<endl;
        if (last) {
            cout<<"  maximum possible interceptions: "<<res<<endl;
            break;
        }
        cout<<"  maximum possible interceptions: "<<res<<endl<<endl;
    }
    return 0;
}
