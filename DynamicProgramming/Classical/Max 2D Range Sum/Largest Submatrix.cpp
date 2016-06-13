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
long long length = 0;
long long negInf = -127*100*100;
int main() {
    // freopen("crosses.in" , "r", stdin);
    // freopen("crosses.out", "w", stdout);
    int z;
    cin>>z;
    while(z--){
        long long maxSubRec = negInf;
        long long arr[25+5][25+5];
        string x[25+5];
        cin>>x[0];
        length = x[0].length();

        for (int i=1; i<length; i++)
            cin>>x[i];
        for (int i=0; i<length; i++){
            for (int j=0; j<length; j++){
                if (x[i][j]=='0') {
                    arr[i][j]=0;
                }else{
                    arr[i][j]=1;
                }
                if (i>0) arr[i][j]+=arr[i-1][j];
                if (j>0) arr[i][j]+=arr[i][j-1];
                if (i>0&&j>0)arr[i][j]-=arr[i-1][j-1];
            }
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
        if (z) {
            cout<<maxSubRec<<endl<<endl;
        }else{
            cout<<maxSubRec<<endl;

        }

    }
}
