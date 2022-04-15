#include <stdio.h>
int delete(char *p1,char *p2,int i){
	int n = 0,j = 0;
	int flag = 0;
	for(;j < i;j++){
		if (((*p1) !=' ')&&((*p1) != '\t')){
			*(p2++) = *(p1++);
			n++;
			flag = 1;
			if ((*(p1-1)) == '\n') flag = 0;
		}
	    else if((*p1)=='\t') p1++;
	    else if(((*p1)==' ')&&(flag == 0)) p1++;
	    else {
		    *(p2++) = *(p1++);
			n++;
		}
	}
	return n;
}
int main(){
	char a[99],b[99];
	int i = 0;
	while ((scanf("%c",&a[i])) != EOF) i++;
	char *p1 = &a[0];
	char *p2 = &b[0];
	int n = delete(p1,p2,--i);
	for (i = 0;i < n;i++) printf("%c",b[i]);
	printf("\n");
	return 0;
}
