#include <stdio.h>
#include "math.h"
int prime(int x){
    for(int i=2;i<=sqrt(x);i++)
    {
        if(!(x%i)) return 0;
    }
    return 1;
}
int p(int x){
    int a,b;
    for (a = 2; a < x; a++)
    {
        b = x - a;
        if (prime(a) && prime(b))
        {
            printf("%d=%d+%d\n", x, a, b);
            break;
        }
    }
}
int main()
{
    int n,a,b;
    while ((scanf("%d",&n))!=EOF)
    {
        if(n>=4) {
            p(n);
        }
        else break;
    }
    return 0;
}
