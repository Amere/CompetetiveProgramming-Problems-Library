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
#define INF 1e9
#define llINF 9223372036854775807
#define EPS 1e-9
#define PI acos(-1.0) // important constant; alternative #define PI (2.0 * acos(0.0))
using namespace std;
#define DFS_WHITE -1
#define DFS_BLACK 1
#define DFS_GRAY 2
#define REP(i, a, b) \
for (int i = int(a); i < int(b); i++)

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef map<int, int>::iterator it_type;
typedef long long ll;
typedef map<int, int> mii;
typedef std::pair<int, int> myPair_type;
struct mypair_comp{
    bool operator()(myPair_type const& lhs, myPair_type const& rhs){
        return lhs.first < rhs.first;
    }
};

int inversionIndex(vector<int> v){
    int res = 0;
    for (int i=0; i<v.size(); i++) {
        for (int j=i+1; j<v.size(); j++) {
            if (v[i]>v[j]) {
                res++;
            }
        }
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    set<int> s;
    map<int,int> l;
    map<int,int> r;
    vector<int> results;
    int root;
    cin>>root;
    s.insert(root);
    for (int i=0; i<n-1; i++) {
        int t;
        cin>>t;
        auto it = s.upper_bound(t);
        if (it == s.end() || l.count(*it)!=0) {
            it--;
            r[*it] = t;
            s.insert(t);
            results.push_back(*it);
        }else{
            l[*it] = t;
            s.insert(t);
            results.push_back(*it);
        }
        //s.insert(make_pair(t, -1));
    }
    for (int i=0; i<results.size(); i++) {
        if (i!=results.size()-1) {
            cout<<results[i]<<" ";
        }else{
            cout<<results[i];
        }
    }
    return 0;
}
