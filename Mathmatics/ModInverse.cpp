/*
(a / b) mod p = ((a mod p) * (b^(-1) mod p)) mod p
p = prime, b^(-1) mod p = b^(p - 2) mod p
*/

long long inv(long long x){
    long long r,y;
    for(r=1,y=M-2;y;x=x*x%M,y>>=1)(y&1)&&(r=r*x%M);
    return r;
}
