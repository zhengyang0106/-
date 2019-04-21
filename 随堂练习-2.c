/*************************************************************************
	> File Name: 随堂练习-2.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年04月18日 星期四 11时10分10秒
 ************************************************************************/

#include<stdio.h>
    void test3() {
        char str[100] = "123 456 789";
        int a, b, c;
        scanf("%d", &a);
        scanf("%d", &b);
        scanf("%d", &c);
        printf("%d %d %d\n", a, b, c);
        return ;

}

    void test2() {
            char str[100] = "123 456 789";
            int a, b, c;
            sscanf(str, "%d", &a);
            sscanf(str + 4, "%d", &b);
            sscanf(str + 8, "%d", &c);
            printf("%d %d %d\n", a, b, c);
            return ;

    }

    void test1() {
            char str[100];
            scanf("%[^\n]s", str);// getchar();
            int ret = printf("%s", str);
            printf(" has %d digits\n", ret);
            scanf("%[^\n]s", str); getchar();
            ret = printf("%s", str);
            printf(" has %d digits\n", ret);
            return ;

    }

    int main() {
            test2();    
            return 0;

    }

