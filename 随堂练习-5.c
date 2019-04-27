/*************************************************************************
	> File Name: 随堂练习-5.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年04月21日 星期日 14时04分09秒
 ************************************************************************/

/*
#include<stdio.h>
// 二分查找
int brinary_search(int (*num)(int), int n, int val) {//　数组是展开的函数　函数是数据的压
    int head = 0, tail = n -1, mid;
    while (head <= tail ) {
        mid = (head + tail) >>  1;   //   >> 相当于除以　2
        if (num(mid) == val) return mid;
        if (num(mid) < val )  head = mid + 1;
        else tail = mid - 1; 
    }
    return -1;
}

int Hexagonal (int n) {
    return n * (2 *n - 1);
}
int pentagonal (int n) {
    return n * (3 * n - 1) / 2;
}


int main() {
    int n = 166;
    while (brinary_search (Hexagonal, n, pentagonal(n)) == -1) n++;
    printf("%d\n",pentagonal(n));

    return 0;
}
*/

#include<stdio.h>


int Hexagonal (int n) {
    return n * (2 *n - 1);
}
int pentagonal (int n) {
    return n * (3 * n - 1) >> 1;
}

int brinary_search (int (*num)(int), int n, int val) {
    int head = 0, tail = n -1, mid;
    while(head <= tail) {
        mid = head + tail >> 1;
        if (num(mid) == val) return mid;
        if (num(mid) <  val) {
            head = mid + 1;
        } else tail = mid -1;

    }
    return -1;

}

int main() {
    int n = 166;
    while (brinary_search (Hexagonal, n, pentagonal(n)) == -1)
    n++;
    printf("%d\n",pentagonal(n));
    return 0;
}

