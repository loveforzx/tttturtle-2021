#include<stdio.h>
int main()
{
    unsigned short x,m,n;
    scanf("%hx%hu%hu",&x,&m,&n);
    if ((0<=m)&&(m<=15)&&(1<=n)&&(n<=(16-m)))
        printf("%hx",x<<=(16-m-n));
    else printf("error");
    return 0;
}
