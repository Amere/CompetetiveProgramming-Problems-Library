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
int len;
string s;
long long pow1(int n){
    return (long long)pow(10,len-n-1);
}
long long memo[19][1025][1025][2];
long long solve(int idx,int msk1,int msk2,int bol){
    if (idx==len) {
        return 0;
    }
    if (memo[idx][msk1][msk2][bol]!=-1) {
        return memo[idx][msk1][msk2][bol];
    }
    long long result = 0;
    if (bol) {
        for (long long i=0; i<10; i++) {
            if(((msk1>>i)&1)!=1){
                result = max(result,i*pow1(idx)+solve(idx+1, msk1|(1<<i), msk2, 1));
            }else{
                if (((msk2>>i)&1)!=1) {
                    result = max(result,i*pow1(idx)+solve(idx+1, msk1,msk2|(1<<i), 1));
                }
            }
        }
    }else{
        for (int i=0; i<s[idx]-'0'; i++) {
            if(((msk1>>i)&1)!=1){
                result = max(result,i*pow1(idx)+solve(idx+1, msk1|(1<<i), msk2, 1));
            }else{
                if (((msk2>>i)&1)!=1) {
                    result = max(result,i*pow1(idx)+solve(idx+1, msk1,msk2|(1<<i), 1));
                }
            }
        }
        if(((msk1>>(s[idx]-'0'))&1)!=1){
            result = max(result,(s[idx]-'0')*pow1(idx)+solve(idx+1, msk1|(1<<(s[idx]-'0')), msk2, 0));
        }else{
            if(((msk2>>(s[idx]-'0'))&1)!=1){
                result = max(result,(s[idx]-'0')*pow1(idx)+solve(idx+1, msk1,msk2|(1<<(s[idx]-'0')), 0));
            }
        }
    }
    return memo[idx][msk1][msk2][bol]=result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>s) {
        len = (int)s.length();
        memset(memo, -1, sizeof(memo));
        cout<<solve(0, 0, 0, 0)<<endl;
    }
    return 0;
}
