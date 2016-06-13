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
long long negInf = -127*100*100;
int main() {
    // freopen("crosses.in" , "r", stdin);
    // freopen("crosses.out", "w", stdout);
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        long long maxSubRec = negInf;
        int arr[300][300];
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cin>>arr[i][j];
                arr[i+n][j]=arr[i][j+n]=arr[i+n][j+n]=arr[i][j];
            }
           // cout<<endl;
        }
        for (int i=0; i<2*n; i++){
            for (int j=0; j<2*n; j++){
                if (i>0) arr[i][j]+=arr[i-1][j];
                if (j>0) arr[i][j]+=arr[i][j-1];
                if (i>0&&j>0)arr[i][j]-=arr[i-1][j-1];
                //cout<<arr[i][j]<<" ";
            }
            // cout<<endl;
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                for (int k=i; k<n+i&&k<2*n; k++) {
                    for (int l=j; l<j+n&&l<2*n; l++) {
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
        maxSubRec = (maxSubRec==negInf ? 0 : maxSubRec);
            cout<<maxSubRec<<endl;

    }
}
