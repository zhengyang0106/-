/*************************************************************************
	> File Name: 5-随堂练习.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年05月04日 星期六 14时28分58秒
 ************************************************************************/

#include<stdio.h>

#define MAX_N 10000
int prime[MAX_N + 5] = {0};

int main() {
    for(int i = 2; i * i < MAX_N; i++) {
        if (prime[i]) continue;
        for(int j = i* i; j <= MAX_N; j += i){//j+=i j就是 每次倍数 +1   // 为甚么要从 i×i 开始呢  因为   i* 比 i晓得数 已经被标记过了
            prime[j] = 1;
        } 
    }
    for (int i= 2; i<= MAX_N; i++) {
        if(prime[i]) continue;
        prime[++prime[0]] = i;
    }
    int n;
    while (~scanf("%d",&n)) {
        printf("%d", prime[n]);
    }

    return 0;
}
