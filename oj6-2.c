#include <stdio.h>
void turn(int *p,int x,int y,int a[x][y]){
    for(int i=0;i<x;i++)
    {
        if(i==x-1) printf("%d",a[i][y-1]);
        else printf("%d ",a[i][y-1]);
    }

    printf("\n");
    for(int j=0;j<y-1;j++)
    {
        for(int t=0;t<x;t++)
        {
            p=&a[t][y-1-j];
            --p;
            if(t==x-1)printf("%d",*p);
            else printf("%d ",*p);
        }
        printf("\n");
    }

}
int main() {
    int x,y;
    scanf("%d%d",&x,&y);
    int a[x][y];
    for(int i=0;i<x;i++)
        for(int j=0;j<y;j++)
            scanf(" %d",&a[i][j]);
    int *p=a;
    turn(p,x,y,a);
    return 0;
}
