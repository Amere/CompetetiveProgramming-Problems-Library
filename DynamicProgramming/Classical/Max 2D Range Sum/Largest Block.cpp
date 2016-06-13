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
int length = 0;
long long negInf = -127*100*100;
int main() {
    // freopen("crosses.in" , "r", stdin);
    // freopen("crosses.out", "w", stdout);
    int z;
    cin>>z;
    while(z--){
        long long maxSubRec = negInf;
        int arr[100+5][100+5];
       // int x[100+5][100+5];
        cin>>length;
        //length = x[0].length();
        memset(arr, 1, sizeof arr);
        for (int i=0; i<105; i++) {
            for (int j=0; j<105; j++) {
                arr[i][j]=1;
            }
        }
        int blocks;
        cin>>blocks;
        while (blocks--) {
            int c1,c2,r1,r2;
            cin>>r1>>c1>>r2>>c2;
            for (int i=r1-1; i<r2; i++) {
                for (int j=c1-1; j<c2; j++) {
                    arr[i][j]=0;
                }
            }
        }
        for (int i=0; i<length; i++){
            for (int j=0; j<length; j++){
                if (i>0) arr[i][j]+=arr[i-1][j];
                if (j>0) arr[i][j]+=arr[i][j-1];
                if (i>0&&j>0)arr[i][j]-=arr[i-1][j-1];
                //cout<<arr[i][j]<<" ";
            }
           // cout<<endl;
        }
        for (int i=0; i<length; i++) {
            for (int j=0; j<length; j++) {
                for (int k=i; k<length; k++) {
                    for (int l=j; l<length; l++) {
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
                        if((k-i+1)*(l-j+1)==subRec)
                            maxSubRec=max(maxSubRec,subRec);
                    }
                }
            }
        }
        maxSubRec = (maxSubRec==negInf ? 0 : maxSubRec);
            cout<<maxSubRec<<endl;

    }
}
