#include <stdio.h>
int main(){
    float a = 1.75, b = 1.35;
    float c = a + b;
    printf("____\n", c, c);//TODO: 分别输出c保留小数点后6/7位的值
    a = 1.234567e10;
    b = 20;
    c = a + b;
    printf("____\n", c);//TODO: 输出c的值!!注意这里和书上有所不同，只需要输出一次
    return 0;
}