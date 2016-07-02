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
#define PI acos(-1.0);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
#define INF 1000000000
#define llINF 9223372036854775807
#define EPS 1e-9
#define sz(v)        static_cast<int>((v).size())
#define pb(...)      push_back(__VA_ARGS__)
#define mp(x, y)     make_pair((x), (y))
#define clr(x) memset(x, 0, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
ll mo = 1000000007;

int V,E;
int AdjMatrix[55][55];


int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int c = 0;
    while (cin>>E) {
        memset(AdjMatrix, 0, sizeof(AdjMatrix));
        V = 0;
        for (int i=0; i<E; i++) {
            int a,b;cin>>a>>b;
            AdjMatrix[a][b] = 1;
            V = max(V,max(a,b));
        }
        V++;
        for (int k = 0; k < V; k++){
            for (int i = 0; i < V; i++){
                for (int j = 0; j < V; j++){
                    if (AdjMatrix[i][k]&&AdjMatrix[k][j]) {
                        AdjMatrix[i][j] += AdjMatrix[i][k] * AdjMatrix[k][j];
                    }
                }
            }
        }
        for (int k = 0; k < V; k++){
            if (AdjMatrix[k][k])
            for (int i = 0; i < V; i++){
                for (int j = 0; j < V; j++){
                    if (AdjMatrix[i][k]&&AdjMatrix[k][j]) {
                        AdjMatrix[i][j]= -1;
                    }
                }
            }
        }
        cout<<"matrix for city "<<c<<endl;
        for (int i = 0; i < V; i++){
            for (int j = 0; j < V; j++){
                if (j)
                    cout<<" "<<AdjMatrix[i][j];
                else
                    cout<<AdjMatrix[i][j];
            }
            cout<<endl;
        }
        c++;
    }

    return 0;
}
