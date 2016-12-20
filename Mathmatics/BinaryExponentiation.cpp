/* log(n) algorithm to compute x^n;
*/

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
