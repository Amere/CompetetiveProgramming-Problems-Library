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
int INF = 2000000000;
long long sumDiv[20000000+6];
long long accSum[20000000+6];
int N = 20000002;
void modifiedSieve(){
    for (int i=0; i<20000000+3; i++) {
        sumDiv[i]=1;
    }
    for (int i=2; i<N; i++) {
        if (sumDiv[i]==1) {
            for (int j=i; j<N; j+=i) {
                int e=0;
                int k=j;
                while (k%i==0) {
                    k/=i;
                    e++;
                }
                sumDiv[j]*=((long long)pow(i,e+1)-1)/(i-1);
            }
        }
    }
    for (int i=1; i<N; i++) {
        accSum[i] = accSum[i-1]+sumDiv[i];
    }
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    modifiedSieve();
    int n;
    while (true) {
        cin>>n;
        if (n==0) {
            break;
        }
        cout<<accSum[n]-1<<endl;
    }

    return 0;
}
