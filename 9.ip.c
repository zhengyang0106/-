/*************************************************************************
	> File Name: 9.ip.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年05月16日 星期四 18时56分35秒
 ************************************************************************/

#include<stdio.h>

union IP {
    unsigned int  num;
    unsigned char ip[4];
}
int is_little() {//判断大小端机器
    static int a = 1;
    return ((char *)(&a))[0];
}
int main() {
    printf("%d\n", is_little());
    char str[25]
    while(~scanf("%s", &str)) {
        int a,b,c,d;
        sscanf(str,"%s.%s.%s.%s",&a, &b, &c, &d);
        IP ip;
        ip.ip[3] = a;
        ip.ip[2] = b;
        ip.ip[1] = c;
        ip.ip[0] = d;
        printf("%s = %u\n", str, ip.num);

    }
   
    return 0;


