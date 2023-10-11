#include<stdio.h>
int main(){
    int i = ; //TODO: 最大的int值
    unsigned u = ; //TODO: 最大的unsigned int值
    float f;
    i++;
    printf("int overflow: %d\n", i);
    i--;
    printf("int underflow: %d\n", i);
    i = i * 3;
    printf("int operation overflow: %d\n", i);
    u++;
    printf("unsigned int overflow: %u\n", u);
    i = ;//TODO: float对应的正无穷大
    f = *(float*)&i;
    printf("float_INF: %g\n", f);
    i = ;//TODO: 对应float, 不是有效数值
    f = *(float*)&i;
    printf("float_NaN: %g\n", f);
    return 0;
}