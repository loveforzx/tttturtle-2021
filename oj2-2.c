#include<stdio.h>
int main()
{
    int a=1;
    int i,j,b,c,N,h;
    scanf("%d",&N);
    for(i=0;i<=N;)
    {
        for(h=1;h<=N+2*(N-i);h++)
            printf(" ");
        printf("%d",a);
        printf("   ");
        for(j=1;j<=i;)
        {
            b=a*(i-j+1)/j;
            printf("%d",b);
            c=b/10;
            if (c!=0)printf("  ");
            else printf("   ");
            a=b;j++;
        }
        printf("\n");i++;
    }
    return 0;
}
