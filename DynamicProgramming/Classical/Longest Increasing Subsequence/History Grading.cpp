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
int arr[25];
int arri[25][25];
int memo[25];
map<int, int> m;
int negInf = -10e9;
int main() {
    // freopen("crosses.in" , "r", stdin);
    // freopen("crosses.out", "w", stdout);
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>arr[i];
        m[arr[i]]=i;
    }
    memset(arr, 0, sizeof (arr));
    while (cin>>arr[0]) {
        memset(arri, 0, sizeof(arri));
        map<int,int> t;
        t[arr[0]]=0;

        for (int i=1; i<n; i++) {
            cin>>arr[i];
            t[arr[i]]=i;
        }

        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (m[i]==t[j]) {
                    arri[i][j]=arri[i-1][j-1]+1;
                }else{
                    arri[i][j]=max(arri[i-1][j],arri[i][j-1]);
                }
            }
        }
        cout<<arri[n][n]<<endl;

    }
    return 0;
}
