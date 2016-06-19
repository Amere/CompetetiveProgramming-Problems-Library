
/*
Property1 : Zeckndorf's theorem states that any number could be expressed by fibonacci numbers and will never be using
any two consecutive ones

Property2 : Pisano Perios states that fibonacci numbers preiodise over any mod operation over them
*/


/*
fib[n+1]*fib[n-1]-(fib[n])^2 = (-1)^n;
fib[n+k] = fib[k]*fib[n+1] + fib[k-1]*fib[n];
fib[2n] = fib[n]*(fib[n+1]+fib[n-1]);

GCD-equality
gcd(FIBm,FIBn) = fib[gcd(m,n)];
*/
/* Computing fibonacci in O(1) by Radicals buut it's not sufficient for big fib numbers
fib(n) = (((1+sqrt(5))/2)^n)/sqrt(5);
*/
/* coputing fibonacci in O(logn) by efficient identity matrix and binray exponentiation*/
/*
(fib(n-1) fib(n-2)) * (0 1) = (fib(n) fib(n-1))
                      (1 1)
*/
int fib[];

int fibonacci(int n){
    
    if (n == 0)
        return 0;
    if (n <= 2)
        return 1;
    if (fib[n] != -1)
        return fib[n];
    
    int k = n >> 1;
    int a = fibonacci(k), b = fibonacci(k+1);
    
    if (n%2 == 0)
        return fib[n] = a * (2 * b - a);
    return  fib[n] = b * b + a * a;
}
/*Fibonacci for negative numbers

fib(n-2) = fib(n)-fib(n-1)
so
fib(-n) = (-1)^(n+1) * fib(n)
*/
/*
summation(fib(i))form1->n = fib(n+2)-1;
summation(fib^2(i))from1->n = fib(n)*fib(n+1);
*/
