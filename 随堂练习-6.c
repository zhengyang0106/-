/*************************************************************************
	> File Name: 随堂练习-6.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年04月21日 星期日 16时30分53秒
 ************************************************************************/
/*
#include<stdio.h>
int x, y;
int gcd (int a, int b) {
    return b ? gcd(b, a%b) : a;
}
int ex_gcd(int a, int b) {//对于自然界的正整数　　一定存在　a x + b y = gcd(a,b);的解
    if (b == 0) {
        x = 1,
        y = 0;
        return a;
    }
    int r = ex_gcd(b, a % b), t = x;
    x = y;
    y = t - y * (a / b);
    return r;
}
int main() {
    int n , m;
    while(~scanf("%d%d",&n,&m)) {
        ex_gcd(n, m);
        printf("%d * %d + %d * %d = %d\n", n, x, m, y,n * x + m * y);
        printf("%d * %d + %d * %d = %d\n", n, x, m, y,ex_gcd(n,m));
    }


    return 0;
}
*/



#include<stdio.h>
int x, y;
int ex_gcd (int a,int b) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = ex_gcd (b, a % b), t = x;
    x = y;
    y = t - y * (a / b);
    return r;
}

int main() {
    int m,n;
    while (~scanf("%d%d",&m,&n)) {
        ex_gcd(m,n);
        printf("%d",m);
        printf("%d",n);
        printf("%d * %d + %d * %d = %d\n",m,x,n,y,ex_gcd(m, n));
    }
    return 0;
}
