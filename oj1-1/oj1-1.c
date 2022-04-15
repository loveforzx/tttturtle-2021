#include<stdio.h>
int main()
{
    char c;
    while(c!=EOF)
    {
        c=getchar();
        (c>='A'&&c<='Z')?c=c-'A'+'a':c;
        if(c!=EOF)
            putchar(c);
    }
    return 0;
}
