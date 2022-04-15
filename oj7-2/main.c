#include <stdio.h>
#include "stdlib.h"
#include "string.h"
static int n;
struct student{
    int num;
    char name[20];
    int english,math,physics,c;
    float aver;
    struct student *next;
};
void input(struct student*p){
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        struct student*s=(struct student*) malloc(sizeof (struct student));
        scanf("%d%s%d%d%d%d",&s->num,s->name,&s->english,&s->math,&s->physics,&s->c);
        p->next=s;
        s->next=NULL;
        p=s;
    }
    printf("完成了%d位同学的成绩输入。\n",n);
}
void output(struct student*p){
    while(p->next!=NULL)
    {
        printf("%d %s %d %d %d %d\n",p->next->num,p->next->name,p->next->english,p->next->math,p->next->physics,p->next->c);
        p=p->next;
    }
}
int  change(struct student*p,int a){
    int meun2;
    while(p->next->num!=a)
        p=p->next;
    if(p->next==NULL) return 0;
    else
    {
        scanf("%d",&meun2);
        switch (meun2) {
            case 0:
                scanf("%s",p->name);break;
            case 1:
                scanf("%d",&p->english);break;
            case 2:
                scanf("%d",&p->math);break;
            case 3:
                scanf("%d",&p->physics);break;
            case 4:
                scanf("%d",&p->c);break;
        }
        return 1;
    }
}
void average(struct student*p){
    for(int i=0;i<n;i++)
    {
        p->next->aver=((float )p->next->c+(float )p->next->physics+(float)p->next->math+(float)p->next->english)/4;
        printf("%d %s %2.2f\n",p->next->num,p->next->name,p->next->aver);
        p=p->next;
    }
}
void output1(struct student*p){
    int total;
    for(int i=0;i<n;i++)
    {
        total=p->next->english+p->next->math+p->next->c+p->next->physics;
        p->next->aver=total/4;
        printf("%d %s %d %2.2f\n",p->next->num,p->next->name,total,p->next->aver);
        p=p->next;
    }
}
void sort(struct student*p1){
    float temp;
    struct student *temp2=p1;
    struct student *p2;
    int t,i,j;
    char a[20];
    for(int i=0;i<n;i++)
    {
        p1->next->aver=((float )p1->next->c+(float )p1->next->physics+(float)p1->next->math+(float)p1->next->english)/4;
        p1=p1->next;
    }
    p1=temp2;
    for(i=0,p1=p1->next;i<n-1;i++,p1=p1->next)
        for(j=0,p2=p1->next;j<n-i-1;j++,p2=p2->next)
        {
            if(p1->aver>p2->aver)
            {
                t=p1->num;
                p1->num=p2->num;
                p2->num=t;
                temp=p1->aver;
                p1->aver=p2->aver;
                p2->aver=temp;
                strcpy(a,p1->name);
                strcpy(p1->name,p2->name);
                strcpy(p2->name,a);
            }
        }
    for(int i=0;i<n;i++,temp2=temp2->next)
        printf("%d %s %2.2f\n",temp2->next->num,temp2->next->name,temp2->next->aver);
}
int main() {
    struct student*head=(struct student*)malloc(sizeof (struct student));
    head->next=NULL;
    struct student*p;
    p=head;
    int meun1=0,number;
    while((scanf("%d",&meun1))!=EOF)
    {
        switch (meun1) {
            case 0: return 0;
            case 1:
                input(p),p=head;break;
            case 2:
                output(p),p=head;break;
            case 3:
                scanf("%d",&number);
                change(p,number),p=head;break;
            case 4:
                average(p),p=head;break;
            case 5:
                output1(p),p=head;break;
            case 6:
                sort(p),p=head;break;
        }
    }
    return 0;
}

