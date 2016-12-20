
/* Power Exponentiation */  //Log(b)
int exp(int a, int b, int c)  //Recursive
{
    if(b==0) return 1;
    if(b%2==0)
    {
        int x=exp(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * exp(a,b-1,c))%c;
}
int modPow(int a, int e, int mod)	// Iterative
	{
		a %= mod;
		int res = 1;
		while(e)
		{
			if((e & 1) == 1)
				res = (res * a) % mod;
			a = (a * a) % mod;
			e >>= 1;
		}
		return res;
	}



/* Metrices Basic Operations */
#define rep(i, v) for(int i=0;i<sz(v);++i)
typedef vector<int> row;
typedef vector<row> matrix;

matrix zero(int n,int m){
  return matrix(n,row(m,0));
}

matrix identity(int n){ //Always square matrix
  matrix ret = zero(n,n);
  rep(i,ret) ret[i][i] = 1;
  return ret;
}

int matrixTrace(matrix a){ //sumOfDigonal Values
  int ret = 0;
  rep(i,a) ret+=a[i][i];
  return ret;
}

matrix rotate(matrix v){ //rotate clockwise
  matrix r = zero(sz(v[0]),sz(v));
  rep(i,v)
      rep(j,v[0])
        r[j][sz(v)-1-i] = v[i][j];
  return r;
}

matrix reflect(matrix v) {
  matrix r = zero(sz(v),sz(v[0]));
  rep(i,v)
    rep(j,v[0])
      r[i][sz(v[0])-1-j] = v[i][j];
  return r;
}

matrix add(matrix a,matrix b) {
  matrix ret = zero(sz(a),sz(a[0]));
  rep(i,a) rep(j,a[0]) ret[i][j] = a[i][j] + b[i][j];
  return ret;
}

matrix addIdentity(matrix a){
  rep(i,a) ++a[i][i];
  return a;
}

matrix multiply(matrix a,matrix b){
  matrix ret = zero(sz(a), sz(b[0]));
  // Optimizations here not to enter the last loop of a[i][k] = 0
  // Also we can swtich last two loops if b[k][j] has more zeros

  //for MOD optimization we use the following
  rep(i,a) {
    rep(k,a[0]){
      ll res = 0;
      long long MOD2 = 8LL * MOD * MOD;
      rep(j,b[0]) {
        res += a[i][k] * b[k][j];
        if (res >=MOD2) {
          res -= MOD2;
        }
      }
    }
    ret[i][j] = res % MOD;
  }
}

matrix matPow(matrix a, ll k){ //N^3 LOG
  if(k==0) return identity(sz(a));
  if (k%2) {
    return multiply(a,matPow(a,k-1));
  }
  return matPow(multiply(a,a),k/2);
}

matrix sumPows(matrix a,ll k){ //Log
  if (k==0) {
    return zero(sz(a),sz(a));
  }
  if (k%2==1) {
    return multiply(a,addIdentity(sumPows(a,k-1)));
  }
  return multiply(sumPows(a,k/2),addIdentity(matPow(a,k/2)));
}


// XY-plane operation using Matices

/*
Rotation clockwise for point (x,y)

[x_,y_] = [cos(theta) sin(theta)]  * [x,y]
          [-sin(theta) cos(theta)]

Rotation counterclockwise

[x_,y_] = [cos(theta) -sin(theta)]  * [x,y]
          [sin(theta) cos(theta)]

*/
