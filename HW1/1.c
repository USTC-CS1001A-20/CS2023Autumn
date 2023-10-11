#include <stdio.h>
int main(){
    printf("sizeof(int)=%d\n", sizeof(int));
    printf("sizeof(char)=%d\n", sizeof(char));
    printf("sizeof(____)=%d\n", sizeof(float)); //TODO:
    printf("sizeof(double)=%d\n", sizeof(/*____*/));//TODO:
    printf("sizeof(long)=%d\n", sizeof(long));
    printf("sizeof(____)=%d\n", sizeof(/*____*/));//TODO: unsigned 类型占用空间数
    return 0;
}