/*************************************************************************
	> File Name: 随堂练习4.c
	> Author:zhengyang 
	> Mail:1021606521@qq.com 
	> Created Time: 2019年04月20日 星期六 15时20分28秒
 ************************************************************************/


#include<stdio.h>
int zhixian(int x, int k, int b) {
    int y = k * x + b;
    return y;
} 

int main() {
    int x, k, b;
    scanf("%d %d %d",&x,&k,&b);
    printf("%d\n",zhixian(x , k, b));
    return 0;
}


/*
int main() {
   // int n = 100;
 //  while(~ scanf("%d",&n) && n != 0){

    if (!n)
    printf("FOLLISH\n");
    else if (n < 60) // 注意条件的冗余　　
    printf("FALL\n");
    else if (n <= 75) // 例：　此处写为　ｎ　>= 60 && n <= 75 
    printf("MEDTUM\n");
    else 
    printf("GOOD\n");
    */

/*  switch (n) {
        case 1 :  
            printf("one "); 
        case 2 : 
            printf("two "); 
        case 3 : 
            printf("three\n");
        break;
        default :
            printf("error\n");
    }
   }
*/
      /* while (n) {
           printf("%d\n", n--);
       }
*/
  /*  int n;
    scanf("%d\n",&n);
    int digit = 1;

    while(n) {
        digit++;
        n /= 10;
    }
    printf("%d\n",digit);

*/


    
 //   for (int n = 1; n <= 100; n++) {
  //      printf("%d\n",n);
  //  }
//return 0;
//}

