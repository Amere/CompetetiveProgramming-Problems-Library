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

vector<vi> AdjList;
int n,q;
vector< vi> parents;
vi match, vis;
int Aug(int l) {
    if (vis[l]) return 0;
    vis[l] = 1;
    for (int j = 0; j < (int)AdjList[l].size(); j++) {
        int r = AdjList[l][j];
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l; return 1;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    while (cin>>n>>q) {
        parents.clear();
        parents.assign(n, vi());
        bool fullGene = false;
        for (int i=0; i<n; i++) {
            int t;
            cin>>t;
            if (t==n) {
                fullGene = true;
            }
            for (int j=0; j<t; j++) {
                int tt;
                cin>>tt;
                tt--;
                parents[i].push_back(tt);
            }
        }
        while (q--) {
            AdjList.assign(2*n, vi());
            int cur;
            cin>>cur;
            if (cur==0) {
                if (!fullGene) {
                    cout<<"Y\n";
                }else{
                    cout<<"N\n";
                }
                continue;
            }
            vi genes;
            for (int i=0; i<cur; i++) {
                int z;
                cin>>z;
                z--;
                genes.push_back(z);
            }
            for (int i=0; i<n; i++) {
                for (int j=0; j<parents[i].size(); j++) {
                    for (int k=0; k<genes.size(); k++) {
                        if (parents[i][j] == genes[k]) {
                            AdjList[i].push_back(genes[k]+n);
                        }
                    }
                }
            }
            int MCBM = 0;
            match.assign(2*n, -1);
            for (int l = 0; l < n; l++) {
                vis.assign(2*n, 0);
                MCBM += Aug(l);
            }
            if (MCBM==cur) {
                cout<<"Y\n";
            }else{
                cout<<"N\n";
            }
        }
    }
    return 0;
}
