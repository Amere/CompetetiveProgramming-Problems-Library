






/*
(a / b) mod p = ((a mod p) * (b^(-1) mod p)) mod p
p = prime, b^(-1) mod p = b^(p - 2) mod p
*/


/* Fast power */
int powmod(int x, int n, int P) {
    x %= P;
    int res = 1 % P;
    while (n) {
        if ((n & 1)) {
            res = (res * x) % P;
            n--;
        }
        else {
            x = (x * x) % P;
            n >>= 1;
        }
    }
    return res;
}

/* mod Power */
int exp(int a, int b, int c)
{
    if(b==0) return 1;
    if(b%2==0)
    {
        int x=exp(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * exp(a,b-1,c))%c;
}

/* GCD & LCM */
ll gcd(ll a,ll b) {
  if (b==0) {
    return a;
  }
  return gcd(b,a%b);
}
ll lcm(ll a,ll b){
  return a*(b/gcd(a,b));
}

/* Fast prime check */
bool isPrime(int s){
    for (int i=2; i*i<=s; i++) {
        if (s%i==0) {
            return 0;
        }
    }
    return 1;
}

/* Sieve */ //O(NloglogN)

ll _sieve_size;
bitset<10000010> bs;
vi primes;
void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);
}
}
bool isPrime(ll N) {
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}

/* Prime Factors */ //O(PI(N)) = O(sqrt(N)/ln(n))
vi primeFactors(ll N) {
  vi factors;
  ll PF_idx = 0, PF = primes[PF_idx];
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; factors.push_back(PF); }
    PF = primes[++PF_idx];
  }
  if (N != 1) factors.push_back(N);
  return factors;
}

ll numPF(ll N) { //Count the number of prime factors
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans++; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

ll numDiffPF(ll N) { //Count the number of different prime factors
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans++;                           // count this pf only once
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans++;
  return ans;
}

ll sumPF(ll N) { //Count the summation of prime factors
  ll PF_idx = 0, PF = primes[PF_idx], ans = 0;
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; ans += PF; }
    PF = primes[++PF_idx];
  }
  if (N != 1) ans += N;
  return ans;
}

ll numDiv(ll N) { //Count the number of divisors
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;                                             // count the power
    while (N % PF == 0) { N /= PF; power++; }
    ans *= (power + 1);                              // according to the formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= 2;             // (last factor has pow = 1, we add 1 to it)
  return ans;
}

ll sumDiv(ll N) { //Summation to the divisors
  ll PF_idx = 0, PF = primes[PF_idx], ans = 1;             // start from ans = 1
  while (N != 1 && (PF * PF <= N)) {
    ll power = 0;
    while (N % PF == 0) { N /= PF; power++; }
    ans *= ((ll)pow((double)PF, power + 1.0) - 1) / (PF - 1);         // formula
    PF = primes[++PF_idx];
  }
  if (N != 1) ans *= ((ll)pow((double)N, 2.0) - 1) / (N - 1);        // last one
  return ans;
}
void modifiedSieve(int N)
	{
		numDiv = new int[N];
		sumDiv = new int[N];
		memset(numDiv,1,sizeof(numDiv));
    memset(sumDiv,1,sizeof(sumDiv));
		for(int i = 2; i < N; ++i)
			if(numDiv[i] == 1)
				for(int j = i; j < N; j += i)
				{
					int e = 0, k = j;
					while(k % i == 0) { k /= i; ++e; }
					numDiv[j] *= e + 1;
					sumDiv[j] *= (int)((pow(i, e + 1) - 1) / (i - 1));
				}
	}
ll EulerPhi(ll N) {
  ll PF_idx = 0, PF = primes[PF_idx], ans = N;             // start from ans = N
  while (N != 1 && (PF * PF <= N)) {
    if (N % PF == 0) ans -= ans / PF;                // only count unique factor
    while (N % PF == 0) N /= PF;
    PF = primes[++PF_idx];
  }
  if (N != 1) ans -= ans / N;                                     // last factor
  return ans;
}
