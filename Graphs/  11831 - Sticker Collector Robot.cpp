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
#include <iomanip>
#define pi acos(-1.0)
using namespace std;
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
#define REP(i, a, b) \
for (int i = int(a); i <= int(b); i++)


typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
vector<vii> AdjList;
int INF = 10e9;
typedef long long ll;
typedef map<int, int> mii;

vi dfs_num;
void dfs(int u) {
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            dfs(v.first);
    }
}

stack<int> topoSort;
void dfs2(int u) {
    dfs_num[u] = DFS_BLACK;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (dfs_num[v.first] == DFS_WHITE)
            dfs2(v.first);
    }
    topoSort.push(u);
}

int V, E, a, b, s;
vi p;
void BFS(int V,int E,int s){
    vi dist(V, INF);
    dist[s] = 0;
    queue<int> q; q.push(s);
    p.assign(V, -1);
    int layer = -1;
    bool isBipartite = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (dist[u] != layer)
        layer = dist[u];
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] == 1000000000) {
                dist[v.first] = dist[u] + 1;
                p[v.first] = u;
                q.push(v.first);
            }
            else if ((dist[v.first] % 2) == (dist[u] % 2))
                isBipartite = false;
        }
    }
}

char arr[105][105];
int directX[] = {0,0,-1,1};
int directY[] = {1,-1,0,0};
int main() {
    while (true) {
        int x =0,y =0;
        char orient=' ';
        int X,Y,S;
        cin>>X>>Y>>S;
        if (!X&&!Y&&!S) {
            break;
        }
        memset(arr, -1, sizeof arr);
        for (int i=0; i<X; i++) {
            for (int j=0; j<Y; j++) {
                cin>>arr[i][j];
                if (arr[i][j]=='O'||arr[i][j]=='N'||arr[i][j]=='S'||arr[i][j]=='L') {
                    x=i;
                    y=j;
                    orient=arr[i][j];
                    arr[i][j]='.';
                }
            }
        }
        string directions;
        cin>>directions;
        int count = 0;
        for (int i=0; i<S; i++) {
            if (directions[i]=='D'||directions[i]=='E') {
                if (directions[i]=='D') {
                    switch (orient) {
                        case 'L': orient = 'S';break;
                        case 'O': orient = 'N';break;
                        case 'N': orient = 'L';break;
                        case 'S': orient = 'O';break;
                    }
                }else{
                    switch (orient) {
                        case 'L': orient = 'N';break;
                        case 'O': orient = 'S';break;
                        case 'N': orient = 'O';break;
                        case 'S': orient = 'L';break;
                    }
                }
            }else{
                int newX=x;
                int newY=y;
                switch (orient) {
                    case 'L': newX+=directX[0];newY+=directY[0];break;
                    case 'O': newX+=directX[1];newY+=directY[1];break;
                    case 'N': newX+=directX[2];newY+=directY[2];break;
                    case 'S': newX+=directX[3];newY+=directY[3];break;
                }
                if (newX<X&&newX>=0&&newY<Y&&newY>=0) {
                    if (arr[newX][newY]=='.') {
                        x=newX;
                        y=newY;
                    }else{
                        if (arr[newX][newY]=='*') {
                            count++;
                            x=newX;
                            y=newY;
                            arr[newX][newY]='.';
                        }
                    }
                }
            }
        }
        cout<<count<<endl;;

    }

    return 0;
}
