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
#define amora cout<<"amora l fshee5 :D"<<endl;
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
#define NOT(x)    (1^(x))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
int mod  = 1000000007;
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
void printV(vector<int> v){
    for (int i=0; i<v.size(); i++) {
        if (i) {
            cout<<" "<<v[i];
        }else cout<<v[i];
    }
}
int fixMod(int a){
    return (a % mod + mod) % mod;
}
#define MAX 1000006

struct Node{
    Node() {value=0;}
    Node(int val): value(val){}
    int value;
};

struct SegmentTree{
    int N;
    vector<int> array;
    vector<Node> sTree;

    SegmentTree(vector<int> in):array(in),N((int)in.size()-1),sTree(vector<Node>(N<<1)){}
    void build(int node,int b,int e){
        if(b == e)
            sTree[node] = Node(0);
        else
        {
            int mid = (b + e) >> 1;
            build(node<<1, b, mid);
            build((node<<1) + 1, mid + 1, e);
            sTree[node] = combine(sTree[node<<1], sTree[(node<<1) + 1]);
        }
    }
    Node combine(Node a, Node b)
    {
        return Node(max(a.value,b.value));
    }
    void update_point(int index, int val)			// O(log n)
    {
        index += N - 1;
        sTree[index] = Node(val);
        while(index>1)
        {
            index >>= 1;
            sTree[index] = combine(sTree[index<<1] , sTree[(index<<1) + 1]);
        }
    }

    Node query(int i, int j)
    {
        return query(1,1,N,i,j);
    }

    Node query(int node, int b, int e, int i, int j)	// O(log n)
    {
        if(i>e || j <b)
            return Node(-INF);
        if(b>= i && e <= j)
            return sTree[node];
        Node q1 = query(node<<1,b,(b+e)/2,i,j);
        Node q2 = query((node<<1)+1,(b+e)/2+1,e,i,j);
        return combine(q1 , q2);
    }
};

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    int tC =0;
    int N = 1; while(N < 250*250) N <<= 1;
    vector<int> v(N+1,0);
    SegmentTree S(v);
    S.build(1, 1, (int)v.size()-1);
    while (t--) {
        tC++;
        map<int,int> m;
        int n,p,q;
        cin>>n>>p>>q;
        n*=n;
        p++;
        q++;
        for(int i=1 ;i<=250*250 ;i++){
            S.update_point(i, 0);
        }
        for (int i=0; i<p; i++) {
            int c;
            cin>>c;
            m[c] = i+1;
        }
        vector<pair<int,int>> prin;
        for (int i=0; i<q; i++) {
            int c;
            cin>>c;
            prin.push_back(mp(m[c],i+1));
        }


        sort(prin.begin(), prin.end());
        for (int i=0; i<prin.size(); i++) {
            if (prin[i].first!=0) {
                int cur = S.query(1, prin[i].second).value;
                S.update_point(prin[i].second, cur+1);
            }
        }
        cout<<"Case "<<tC<<": ";
        cout<<S.query(1, n).value<<endl;
     }
    return 0;
}
