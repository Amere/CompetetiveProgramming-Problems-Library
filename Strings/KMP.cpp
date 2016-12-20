int back[1000000];
string p,t;
vi res;
int n;
void kmpPreprocess(){
    int i = 0,j = -1;
    back[0] = -1;
    while (i < n) {
        while (j >=0 && p[i] != p[j]) {
            j = back[j];
        }
        i++,j++;
        back[i] = j;
    }
}
void kmpSearch(){
    res.clear();
    int i = 0, j = 0;
    while (i < t.length()) {
        while (j >= 0 && t[i] != p[j]) {
            j = back[j];
        }
        i++,j++;
        if (j == n) {
            res.pb(i - j);
        }
    }
}
