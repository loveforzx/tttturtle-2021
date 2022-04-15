#include <stdio.h>
#include "stdlib.h"
static int n;
static float aver;
struct student{
    int num;
    char name[20];
    int english,math,physics,c;
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
    float aver[n];
    for(int i=0;i<n;i++)
    {
        aver[i]=((float )p->next->c+(float )p->next->physics+(float)p->next->math+(float)p->next->english)/4;
        printf("%d %s %2.2f\n",p->next->num,p->next->name,aver[i]);
        p=p->next;
    }
}
void output1(struct student*p){
    int total;
    for(int i=0;i<n;i++)
    {
        total=p->next->english+p->next->math+p->next->c+p->next->physics;
        aver=total/4;
        printf("%d %s %d %2.2f\n",p->next->num,p->next->name,total,aver);
        p=p->next;
    }
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
        }
    }
    return 0;
}
