#include <stdio.h>
#include "string.h"
int main() {
    char s1[10],s2[10],origin[500]={'\0'},temp[500];
    int count=0;
    char *p2;
    FILE *p= fopen("d:\\experiment\\1.txt","r+");
    scanf("%s%s",s1,s2);
    fgets(origin,500,p);
    while((p2= strstr(origin,s1))){
        strcpy(temp,p2+ strlen(s1));
        strcpy(p2,s2);
        strcpy(p2+ strlen(s2),temp);
        count++;
    }
    printf("%d\n%s\n", count,origin);
    fclose(p);
    return 0;
}
