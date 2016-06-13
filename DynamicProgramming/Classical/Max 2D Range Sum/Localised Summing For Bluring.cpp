#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <numeric>
#include <functional>
#include <bitset>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <sstream>
#include <iostream>
#include <limits.h>
#include <valarray>
using namespace std;

typedef long long int64;

 int const max = 1000 + 5;

 int arr[max][max];

int main() {
    for (int n, m, x = 0; scanf("%d%d", &n, &m) != EOF; ++x) {
        if (x > 0) puts("");
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                scanf("%d", &arr[i][j]);
                if (i > 0) arr[i][j] += arr[i - 1][j];
                if (j > 0) arr[i][j] += arr[i][j - 1];
                if (i > 0 && j > 0)
                    arr[i][j] -= arr[i - 1][j - 1];
            }
        int64 total = 0;
        for (int i = 0; i + m <= n; ++i)
            for (int j = 0; j + m <= n; ++j) {
                int c = i + m - 1;
                int d = j + m - 1;
                int cur = arr[c][d];
                if (i > 0) cur -= arr[i - 1][d];
                if (j > 0) cur -= arr[c][j - 1];
                if (i > 0 && j > 0)
                    cur += arr[i - 1][j - 1];
                total += (int64) cur;
                printf("%d\n", cur);
            }
        printf("%ld\n", total);
    }
    return 0;
}
