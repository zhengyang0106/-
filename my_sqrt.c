/*************************************************************************
	> File Name: my_sqrt.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年05月05日 星期日 20时08分05秒
 ************************************************************************/
 #include<stdio.h>
 #define EXP 1e-7
 
double my_sqrt(int y) {
    double head = 0, tail = y, mid;
    while (tail - head > EXP) {
        mid = (head + tail) / 2.0;
        if (mid * mid < y) head = mid;
        else tail = mid;
    }
    return head;
    
}


 int main() {
    int y;
     while(~scanf("%d",&y))
     printf("%f\n",my_sqrt(y));
     

     return 0;
 }
