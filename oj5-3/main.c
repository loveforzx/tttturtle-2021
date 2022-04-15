#include <stdio.h>
int size,count=0;
int a[10][10]={0};
int check(int row,int col);
void solve(int row){
    int i;
    if(row>=size) count++;
    else
        for(i=0;i<size;i++)
        {
            if(check(row,i))
            {
                a[row][i]=1;
                solve(row+1);
                a[row][i]=0;
            }
        }
}
int check(int row,int col)
{
    int ok=1;
    for(int i=0;i<row&&ok;i++)
    {
        if(a[i][col]==1)
            ok=0;
    }
    for(int j=1;j<=col&&ok&&j<=row;j++)
    {
        if(a[row-j][col-j]==1)
            ok=0;
    }
    for(int m=1;row-m>=0&&ok&&col+m<size;m++)
    {
        if(a[row-m][col+m]==1)
            ok=0;
    }
    return ok;
}
int main(){
    scanf("%d",&size);
    solve(0);
    if(count!=0) printf("%d",count);
    else printf("无解！");
    return 0;
}