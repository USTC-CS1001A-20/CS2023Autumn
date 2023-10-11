#include <stdio.h>
int main(){
    int i = 0x7fffffff;
    unsigned u = 0xffffffff;
    float f = 0xffffffff;
    printf("int_max=%d\n", i);
    i = ;//TODO: int_min
    printf("int_min=%d\n", i);
    printf("unsigned_max=%u\n", u);
    i = ;//TODO: 四个字节整型存储对应float的最小值
    f = *(float*)&i;
    printf("float_min=%g\n", f);
    i = ;//TODO: 四个字节整型存储对应于从左边最接近0的浮点数
    f = *(float*)&i;
    printf("float_0-=%g\n", f);
    i = ;//TODO: 四个字节整型存储对应于从右边最接近0的浮点数
    f = *(float*)&i;
    printf("float_0+=%g\n", f);
    i = ;//TODO: 四个字节整型存储对应float的最大值
    f = *(float*)&i;
    printf("float_max=%g\n", f);
    return 0;
}