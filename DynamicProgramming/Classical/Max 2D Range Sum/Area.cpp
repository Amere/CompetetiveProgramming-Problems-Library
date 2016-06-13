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
long long negInf = -10e9;
int main() {
    // freopen("crosses.in" , "r", stdin);
    // freopen("crosses.out", "w", stdout);
    int test;
    int num =0;
    cin>>test;
    while(test--){
        num++;
        int x,y,cost;
        int startX = 0;
        int startY = 0;
        int endX = 0;
        int endY = 0;
        cin>>x>>y>>cost;
        long long arr[100+5][100+5];
        long long finalCost = -negInf;
        for (int i=0; i<x; i++){
            for (int j=0; j<y; j++){
                cin>>arr[i][j];
                if (i>0) arr[i][j]+=arr[i-1][j];
                if (j>0) arr[i][j]+=arr[i][j-1];
                if (i>0&&j>0)arr[i][j]-=arr[i-1][j-1];
            }
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
                        if(subRec<=cost&&((k-i+1)*(l-j+1))>((endX-startX+1)*(endY-startY+1))){
                            finalCost = subRec;
                         //   cout<<finalCost<<" "<<"( "<<i<<", "<<j<<") , ( "<<k<<", "<<l<<" )  >>  "<<((k-i+1)*(l-j+1))<<endl;
                            startX = i;
                            startY = j;
                            endX = k;
                            endY = l;
                        }
                        if(subRec<=cost&&((k-i+1)*(l-j+1))==((endX-startX+1)*(endY-startY+1))){
                            if (finalCost>subRec) {
                                finalCost=subRec;
                            }
                        }
                    }
                }
            }
        }
            cout<<"Case #"<<num<<" "<<((endX-startX+1)*(endY-startY+1))<<" "<<finalCost<<endl;

    }
}
