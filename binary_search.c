/*************************************************************************
	> File Name: binary_search.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年05月05日 星期日 19时36分27秒
 ************************************************************************/

#include<stdio.h>


int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n - 1, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}

int main() {
    int n,a;
    int arr[100];
    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
   while(~ scanf("%d",&a))
    printf("%d\n",binary_search(arr, n, a));
}
