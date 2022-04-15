#include <stdio.h>
#include "math.h"
int find(int n){
    int x=0,z=0,i=0,term=0,t;
    t=n;
    z=n/10;
    for(i=1;z>0;i++)
        z/=10;//i是位数
    x=n%10;
    for(int j=i;j>=1;j--)
    {
        term+= pow(x,i);
        n/=10;
        x=n%10;
    }
    if(term==t) return 1;
    else return 0;
}
int main()
{
    int k,count=0,n=1,t=0;
    while(scanf("%d",&k)!=EOF)
    {
        if(k==0) break;
        else
        {
            count=0;
            for (int i = pow(10, k - 1); i < pow(10, k); i++)
                if (find(i)) count++;
            switch (k)
            {
                case 3:
                    printf("3位的水仙花数共有%d个", count);break;
                case 4:
                    printf("4位的四叶玫瑰数共有%d个", count);break;
                case 5:
                    printf("5位的五角星数共有%d个", count);break;
                case 6:
                    printf("6位的六合数共有%d个", count);break;
                case 7:
                    printf("7位的北斗星数共有%d个", count);break;
                case 8:
                    printf("8位的八仙数共有%d个", count);break;
            }
            if(count==1) {
                for (int i = pow(10, k - 1); (i < pow(10, k)); i++)
                    if(find(i)) printf("%d\n",i);
            }
            else{
                n=1;
                for (int i = pow(10, k - 1); (i < pow(10, k))&&(n<count); i++)
                {
                    if(find(i)) {printf("%d,",i);n++;}
                    t=i;
                }
                for(int z=t+1;z< pow(10,k);z++)
                    if(find(z)) printf("%d\n",z);
            }
        }
    }
    return 0;
}