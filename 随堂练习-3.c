/*************************************************************************
	> File Name: 随堂练习-3.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年04月18日 星期四 19时04分24秒
 ************************************************************************/

#include<stdio.h>
#include<math.h>
int main() {
  /*  double a;
    scanf("%lf", &a);
    printf("%lf\n", pow(a, 1 / 3.0));// 三次方根
    printf("%lf",  acos(-1) / 180 * a);// 角度  --> 弧度    acos（-1）  为 pi值
   */
    
    printf("%f",log(25) / log(5));  //   log5(25)  必须用换底公式才能输出　ｍａｔｈ．ｈ　中未定义　log 以５　为底的函数
    return 0;
}
