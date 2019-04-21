/*************************************************************************
	> File Name: 随堂练习-1.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年04月18日 星期四 11时00分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main() {
    /*
    int a;
    scanf("%d",&a);
    printf("%d",printf("%d\n",a));*/
    int n;
    char str[100];
    FILE *fp;
    if((fp = fopen("/dev/null", "w")) == NULL){
        printf ("cannot open");
        exit(0);
    }
    
    while (~scanf ("%d", &n)) {
        printf (" had %d digit \n",printf ("%d",n));
        printf("%d\n",sprintf (str, "%d" , n));
        printf("%d\n",fprintf (fp, "%d", n));
     }

    
    return 0;

    }
