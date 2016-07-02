
/* Not finished yet */


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
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
#define PI acos(-1.0);
#define INF 1000000000
#define llINF 9223372036854775807
#define EPS 1e-9
#define sz(v)        static_cast<int>((v).size())
#define pb(...)      push_back(__VA_ARGS__)
#define mp(x, y)     make_pair((x), (y))
#define clr(x) memset(x, 0, sizeof(x))
#define clr1(x) memset(x, INF, sizeof(x))
#define dREP(i, a, b) for (int i = (a); i >= (b); --i)
#define REP(i, a, b) for (int i = (a); i < (b); ++i)
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
ll mo = 1000000007;

int AdjMatrix[50+5][50+5];
int p[50+5][50+5];
int sum;
set<pair<int, int>> s;

void printPath(int i,int j){
    if (i!=j) {
        printPath(i,p[i][j]);
    }
    cout<<j+1<<" ";
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int nc,dc,nr,nj,a,b,c,cas=0;
    while (true) {
        cas++;
        clr1(AdjMatrix);
        clr(p);
        s.clear();
        sum = 0;
        cin>>nc;
        if (nc==-1)break;
        cin>>dc;
        dc--;
        cin>>nr;
        for (int i=0; i<nr; i++) {
            cin>>a>>b>>c;
            a--,b--;
            AdjMatrix[a][b]=c;
            AdjMatrix[b][a]=c;
        }
        cin>>nj;
        vector<int> judges;
        for (int i=0; i<nj; i++){
            int t;
            cin>>t;
            judges.push_back(t-1);
        }

        for(int i=0 ; i<nc; i++)
            for(int j=0 ;j<nc ; j++)
                p[i][j] = i;


        for (int k = 0; k < nc; k++)
            for (int i = 0; i < nc; i++)
                for (int j = 0; j < nc; j++){
                    if(AdjMatrix[i][k] + AdjMatrix[k][j]<AdjMatrix[i][j]){
                        AdjMatrix[i][j] =  AdjMatrix[i][k] + AdjMatrix[k][j];
                        p[i][j] = p[k][j];
                    }
                }

        vector<vi> ways(nj);
        for (int i=0; i<(int)judges.size(); i++) {
            int j = dc;
            ways[i].push_back(j);
            while (judges[i]!=j) {
                cout<<judges[i]<<" "<<j<<endl;
                if (s.count(ii(j, p[i][j]))==0) {
                    s.insert(ii(j,p[i][j]));
                    s.insert(ii(p[i][j],j));
                    sum+=AdjMatrix[j][p[i][j]];
                }
                j = p[i][j];
                ways[i].push_back(j);
            }
            ways[i].push_back(j);
            reverse(ways[i].begin(), ways[i].end());
        }
        cout<<"Case "<<cas<<": distance = "<<sum<<"\n   ";
        for (int i=0; i<ways.size(); i++) {
            for (int j=0; j<ways[i].size(); j++) {
                if (j) {
                    cout<<"-"<<ways[i][j];
                }else{
                    cout<<ways[i][j];
                }
            }
            if (i!=ways.size()) {
                cout<<"\n   ";
            }else{
                cout<<"\n";
            }
//            printPath(judges[i],j);
            cout<<endl;
        }
    }
    return 0;
}
