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
int inf = 10e9;
int negInf = -10e9;
stack<char> s;
string source,target;
vector<string> result;
int resIdx = 0;
void dfs(int i ,int idx){
    if (s.size()==0&&idx==(int)source.length()) {
        resIdx++;
        result.push_back("");
        return;
    }
    if (idx>source.length()) {
        return;
    }
    stack<char> temp = s;
    string sTemp = result[resIdx];

    s.push(source[idx]);
    result[resIdx]+='i';
    dfs( i, idx+1);
    result[resIdx]=sTemp;
    s=temp;
    if (s.size()!=0&&(s.top()==target[i])) {
        s.pop();
        result[resIdx]+='o';
        dfs(i+1,idx);
    }
}


int main() {
    // freopen("crosses.in" , "r", stdin);
    while (cin>>source>>target) {
        resIdx=0;
        while (s.size()>0) {
            s.pop();
        }
        result.clear();
        result.push_back("");

        cout<<"["<<endl;
        if (source.length()==target.length()) {
            dfs(0, 0);
            for (int i=0; i<result.size()-1; i++) {
                for (int j=0; j<result[i].length(); j++) {
                    if (j==result[i].length()-1) {
                        cout<<result[i][j];
                    }else{
                        cout<<result[i][j]<<" ";
                    }
                }
                cout<<endl;
            }
        }
        cout<<"]"<<endl;
    }

}
