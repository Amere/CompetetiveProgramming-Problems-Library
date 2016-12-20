typedef vector<int> vi;
#define LSOne(S) (S & (-S))
class FenwickTree {
private:
  vi ft;
public:
  FenwickTree() {}
  FenwickTree(int n) { ft.assign(n + 1, 0); }
  int rsq(int b) {
    int sum = 0; for (; b; b -= LSOne(b)) sum += ft[b];
    return sum; }

  int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a - 1)); }

  void adjust(int k, int v) {
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] += v; }
};

int main() {              // idx   0 1 2 3 4 5 6 7  8 9 10, no index 0!
  FenwickTree ft(10);     // ft = {-,0,0,0,0,0,0,0, 0,0,0}
  ft.adjust(2, 1);        // ft = {-,0,1,0,1,0,0,0, 1,0,0}, idx 2,4,8 => +1

  printf("%d\n", ft.rsq(1, 1));  // 0 => ft[1] = 0
  printf("%d\n", ft.rsq(1, 2));  // 1 => ft[2] = 1
  printf("%d\n", ft.rsq(1, 6));  // 7 => ft[6] + ft[4] = 5 + 2 = 7
  printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
  printf("%d\n", ft.rsq(3, 6));  // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1

  ft.adjust(5, 2); // update demo
  printf("%d\n", ft.rsq(1, 10)); // now 13
} // return 0;
/* 2D FENWICK TREE */
int ft[][], maxX, maxY;

    void update(int x, int y, int val)
    {
        int y1;
        while(x <= maxX)
        {
            y1 = y;
            while(y1 <= maxY)
            {
                ft[x][y1] += val;
                y1 += y1 & -y1;
            }
            x += x & -x;
        }
    }
