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
int dp[100+5][100+5];
int length = 0;
long long negInf = -127*100*100;
int main() {
   // freopen("crosses.in" , "r", stdin);
   // freopen("crosses.out", "w", stdout);
    int n;
    while(cin>>n){
    long long maxSubRec = negInf;
    long long arr[n+5][n+5];
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            cin>>arr[i][j];
            if (i>0) arr[i][j]+=arr[i-1][j];
            if (j>0) arr[i][j]+=arr[i][j-1];
            if (i>0&&j>0)arr[i][j]-=arr[i-1][j-1];
        }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=i; k<n; k++) {
                for (int l=j; l<n; l++) {
                    long long subRec = arr[k][l];
                    if (i>0) {
                        subRec-=arr[i-1][l];
                    }
                    if (j>0) {
                        subRec-=arr[k][j-1];
                    }
                    if (i>0&&j>0) {
                        subRec+=arr[i-1][j-1];
                    }
                    maxSubRec=max(maxSubRec,subRec);

                }
            }
        }
    }
    cout<<maxSubRec<<endl;
    }
}
