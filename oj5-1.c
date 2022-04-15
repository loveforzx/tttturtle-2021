#include <stdio.h>
int main() {
    int m;
    char a[32]={'0'};
    scanf("%d",&m);
    const int mask=0x00000001;
    int i,j;
    for(i=31;i>=0;i--)
    {
        a[i]=(m&mask)+'0';
        m>>=1;
    }
    for(j=0;j<32;j++)
        printf("%c",a[j]);
    return 0;
}