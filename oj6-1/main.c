#include <stdio.h>
int main()
{
    long x;
    scanf("%ld",&x);
    char *p=((char*)&x+3);
    char up_half,low_half;
    for(int k=0;k<4;k++)
    {
        low_half=(*p)&0x0f;
        up_half=(*p>>4)&0x0f;
        printf("%llX",up_half);
        printf("%llX",low_half);
        p--;
    }
    return 0;
}