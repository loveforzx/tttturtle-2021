#include <stdio.h>
#include "math.h"
int find(int n){
    int x=0,z=0,i=0,term=0,t;
    t=n;
    z=n/10;
    for(i=1;z>0;i++)
        z/=10;//i��λ��
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
                    printf("3λ��ˮ�ɻ�������%d��", count);break;
                case 4:
                    printf("4λ����Ҷõ��������%d��", count);break;
                case 5:
                    printf("5λ�������������%d��", count);break;
                case 6:
                    printf("6λ������������%d��", count);break;
                case 7:
                    printf("7λ�ı�����������%d��", count);break;
                case 8:
                    printf("8λ�İ���������%d��", count);break;
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