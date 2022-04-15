#include <stdio.h>
void execute(void(*p[])(),int n);
int task0(){
    printf("task0 is called!\n");
}
void task1(){
    printf("task1 is called!\n");
}
void task2(){
    printf("task2 is called!\n");
}
void task3(){
    printf("task3 is called!\n");
}
void task4(){
    printf("task4 is called!\n");
}
void task5(){
    printf("task5 is called!\n");
}
void task6(){
    printf("task6 is called!\n");
}
void task7(){
    printf("task7 is called!\n");
}
void scheduler(){
    int count=0;
    char b[10];
    scanf("%s",b);
    for(int i=0;b[i]!='\0';count++)
        i++;
    int *p[count];
    for(int j=0;j<count;j++)
        switch (b[j]-'0') {
            case 0:p[j]= (int *) task0;break;
            case 1:p[j]= (int *) task1;break;
            case 2:p[j]= (int *) task2;break;
            case 3:p[j]= (int *) task3;break;
            case 4:p[j]= (int *) task4;break;
            case 5:p[j]= (int *) task5;break;
            case 6:p[j]= (int *) task6;break;
            case 7:p[j]= (int *) task7;break;
        }
    execute(p, count);
}
void execute(void(*p[])(),int n){
    for(int i=0;i<n;i++)
        p[i]();
}
int main() {
    scheduler();
    return 0;
}
