#include <stdio.h>
#include "string.h"
void INPUT(int n,char b[][100],int a[])
{
    int i;
    for(i=0;i<n;i++)
        scanf("%s%d",b[i],&a[i]);
    printf("%d records were input!\n",i);
}
void SORT(int n,char b[][100],int a[])
{
    int i,t;
    char c[100];
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j], a[j] = a[j + 1], a[j + 1] = t;
                strcpy(c, b[j]);
                strcpy(b[j], b[j + 1]);
                strcpy(b[j + 1], c);
            }
        }
    }
    printf("Reorder finished!\n");
}
void OUTPUT(int n,char b[][100],int a[])
{
    for(int i=n-1;i>=0;i--)
    {
        printf("%s %d\n",b[i],a[i]);
    }
}
void FIND(int x,int n,char b[][100],int a[])
{
    int front=0, back=n-1, middle;
    while(front<=back){
        middle=(front+back)/2;
        if(x<a[middle]) back=middle-1;
        else if(x>a[middle]) front=middle+1;
        else{
            printf("%s ", b[middle]);
            printf("%d\n", a[middle]);
            break;
        }
    }
    if(x != a[middle]) printf("not found!\n");
}
int main(){
    int i,n,k;
    while ((scanf("%d",&i))!=0)
    {
        if(i==1)
        {
            scanf("%d",&n);
        }
        static int t;
        t=n;
        int a[20];
        char b[20][100];
        switch (i) {
            case 0:
                return 0;
            case 1:
                INPUT(t,b,a);break;
            case 2:
                SORT(t,b,a);break;
            case 3:
                OUTPUT(t,b,a);break;
            case 4:
                scanf("%d",&k);
                FIND(k,t,b,a);break;
        }
    }
    return 0;
}
