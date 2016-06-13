#include <map>
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
using namespace std;
typedef long long ll;
#define N 200005
#define A 1000005
#define BLOCK 447 // ~sqrt(N)
ll cnt[A];
int a[N];
ll ans[N];
ll answer = 0;
struct node {
    int L, R, i;
}q[N];
bool cmp(node x, node y) {
    if(x.L/BLOCK != y.L/BLOCK) {
        return x.L/BLOCK < y.L/BLOCK;
    }
    return x.R < y.R;
}
int main() {
    int n,m;
    scanf("%d %d", &n,&m);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    for(int i=0; i<m; i++) {
        scanf("%d%d", &q[i].L, &q[i].R);
        q[i].L--; q[i].R--;
        q[i].i = i;
    }
    sort(q, q + m, cmp);
    int currentL = 0, currentR = 0;
    for(int i=0; i<m; i++) {
        int L = q[i].L, R = q[i].R;
        while(currentL < L) {
            int position = currentL;
            answer-=(cnt[a[position]]*cnt[a[position]]*a[position]);
            cnt[a[position]]--;
            answer+=(cnt[a[position]]*cnt[a[position]]*a[position]);
            currentL++;
        }
        while(currentL > L) {
            int position = currentL-1;
            answer-=(cnt[a[position]]*cnt[a[position]]*a[position]);
            cnt[a[position]]++;
            answer+=(cnt[a[position]]*cnt[a[position]]*a[position]);
            currentL--;
        }
        while(currentR <= R) {
            int position=currentR;
            answer-=(cnt[a[position]]*cnt[a[position]]*a[position]);
            cnt[a[position]]++;
            answer+=(cnt[a[position]]*cnt[a[position]]*a[position]);
            currentR++;
        }
        while(currentR > R+1) {
            int position = currentR-1;
            answer-=(cnt[a[position]]*cnt[a[position]]*a[position]);
            cnt[a[position]]--;
            answer+=(cnt[a[position]]*cnt[a[position]]*a[position]);
            currentR--;
        }
        ans[q[i].i] = answer;
    }
    for(int i=0; i<m; i++)
        printf("%I64d\n",ans[i]);
    return 0;
}
