#include <stdio.h>
int find(int n)
{
    int term=0;
    for(int i=1;i<n;i++)
    {
        if (n % i == 0) term += i;
    }
    if(term==n) return 1;
    else return 0;
}
int main() {
    int n,term=0;
    for(n=3;n<10000;n++)
    {
        if(find(n))
        {
            printf("%d=1+",n);
            for(int i=2;i<n;i++)
            {
                if(n%i==0)
                {
                    term+=i;
                    if(term==n-1) printf("%d\n",i);
                    else printf("%d+",i);
                }
            }
            term=0;
        }
    }
    return 0;
}
