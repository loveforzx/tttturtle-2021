#include <stdio.h>
int main()
{
    char c;
    enum{A,B,C};
    int state=A;
    while('!'!=(c=getchar()))
    {
        switch (state)
        {
            case 0:
                if (c == ' ')
                {putchar(c), state = B;}
                else
                {putchar(c);}
                break;
            case 1:
                if (c != ' ') { putchar(c), state = A; }
                break;
        }
    }
    putchar('!');
    return 0;
}