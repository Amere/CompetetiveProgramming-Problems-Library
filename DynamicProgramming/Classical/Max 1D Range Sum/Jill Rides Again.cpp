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
int values[20000+5];


int main() {
   // freopen("crosses.in" , "r", stdin);
   // freopen("crosses.out", "w", stdout);
    int n;
    cin>>n;
    int k=0;
    while (n--) {
        k++;
        int route;
        cin>>route;
        for (int i=1; i<route; i++) {
            cin>>values[i];
        }
        int ans=0;
        int res = 0;
        int startF = 1;
        int end = -1;
        int start =1;
        for (int i=1; i<route; i++) {
            res+=values[i];
            if (res<0) {
                start=i+1;
                res=0;
            }
            if(res>ans||(res==ans&&(i-start)>(end-startF))){
                ans = res;
                end=i;
                startF=start;
            }

        }
        if (ans>0) {
            cout<<"The nicest part of route "<<k<<" is between stops "<<startF<<" and "<<end+1<<endl;
        }else{
            cout<<"Route "<<k<<" has no nice parts"<<endl;
        }
    }
}
