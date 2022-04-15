#include<stdio.h>
int main()
{  unsigned long IP,A,B,C,D;

    const unsigned long a=0x000000ff;
    const unsigned long b=0x0000ff00;
    const unsigned long c=0x00ff0000;
    const unsigned long d=0xff000000;
    while(scanf("%lu",&IP)!=EOF){
        A=a&IP;
        B=b&IP;B>>=8;
        C=c&IP;C>>=16;
        D=d&IP;D>>=24;
        printf("%lu.%lu.%lu.%lu\n",D,C,B,A);
    }
    return 0;
}
