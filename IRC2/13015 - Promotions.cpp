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
typedef pair<int, int> ii;
typedef vector<int> vi;

vector<vi> AdjList,AdjList2;
int A,B,E,P;
vi vis;
int dfs(int u,bool x){
    if (vis[u]) {
        return 0;
    }
    vis[u] = 1;
    int res = 1;
    if (x) {
        for (int i=0; i<AdjList[u].size(); i++) {
            int child = AdjList[u][i];
            res += dfs(child,x);
        }
    }else{
        for (int i=0; i<AdjList2[u].size(); i++) {
            int child = AdjList2[u][i];
            res += dfs(child,x);
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(cin>>A>>B>>E>>P){
        AdjList.assign(E, vi());
        AdjList2.assign(E, vi());
        for (int i=0; i<P; i++) {
            int a,b;
            cin>>a>>b;
            AdjList[a].push_back(b);
            AdjList2[b].push_back(a);
        }
        int perA =0;
        int perB =0;
        int never =0;
        for (int i=0; i<E; i++) {
            vis.assign(E, 0);
            int above = 0;
            int under = 0;
            above = E-dfs(i,1)+1;
            vis.assign(E, 0);
            under = dfs(i,0);
            if (under>B) {
                never++;
            }
            if (above <=A) {
                perA++;
            }
            if (above <=B) {
                perB++;
            }
        }
        cout<<perA<<endl;
        cout<<perB<<endl;
        cout<<never<<endl;
    }
    return 0;
}
