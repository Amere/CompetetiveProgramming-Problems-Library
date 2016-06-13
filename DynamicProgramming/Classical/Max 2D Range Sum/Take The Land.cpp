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

    while(true){
        int x ,y;
        cin>>x>>y;
        if (x==0&&y==0) {
            break;
        }
        long long maxSubRec = negInf;
        int arr[100+5][100+5];
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                int temp;
                cin>>temp;
                arr[i][j]=1-temp;
                if (i>0) arr[i][j]+=arr[i-1][j];
                if (j>0) arr[i][j]+=arr[i][j-1];
                if (i>0&&j>0)arr[i][j]-=arr[i-1][j-1];
                //cout<<arr[i][j]<<" ";
            }
           // cout<<endl;
        }
        for (int i=0; i<x; i++) {
            for (int j=0; j<y; j++) {
                for (int k=i; k<x; k++) {
                    for (int l=j; l<y; l++) {
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
