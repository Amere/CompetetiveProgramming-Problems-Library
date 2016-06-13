
/*

This code wil WA beacuse the need of use BigInteger of Java
so just translate to Java and BigInteger and Accepted :)

*/





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
int arr[100+5];
int length = 0;
int negInf = -999999999;
int main() {
   // freopen("crosses.in" , "r", stdin);
   // freopen("crosses.out", "w", stdout);

    while(cin>>arr[0]){
        length = 1;
        for (int i=1; true; i++) {
            int t;
            cin>>t;
            if (t==-999999) {
                break;
            }else{
                length++;
                arr[i]=t;
            }
        }
        memset(dp, negInf, sizeof dp);
        //cout<<dp[0][0]<<" ";
        for (int i=0; i<=length; i++) {
            dp[i][i]=arr[i];
            for (int j=i+1; j<=length; j++) {
                dp[i][j]=dp[i][j-1]*arr[j];
            }
        }
        int max_ = negInf;
        for (int i=0; i<length; i++) {
            for (int j=i; j<length; j++) {
                max_ = max(max_,dp[i][j]);
            }
        }
        cout<<max_<<endl;
    }
}
