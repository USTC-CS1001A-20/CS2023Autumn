#include<stdio.h>
int main(){
    double a;
    scanf("%f\n",a);
    int b = 3;
    if(b=3);
    printf("%f\n",b);
    printf("if b=3, print this sentence\n");
    else printf("N/A");
         printf("if b!=3, print this sentence\n");
    for(n=1;n<=10;n++);
    {
        printf("%d %d\n",n,pow(n,2),"\n");
    }
           fun()； 
    double x;
    int y=5, z=2;
    x = y / z;
    printf("5/2=%f", x);
}
void fun(){
    printf("hello world\n");
}

// scanf要加&
// if后面不要直接接分号，会当成if语句结束
// if后面跟着代码段要用{}括起来,for也是同理
// pow要加math.h，且返回值为double，要用%f来printf
// 一些库函数要stdio.h以外的头文件，常用的有math.h，string.h，stdlib.h
// for后面不要直接接分号，会当成for语句结束，for里面的用的变量要先定义
// scanf：输入的是double，要用%lf；输入的是int，要用%d；输入的是char，要用%c；输入的是字符串，要用%s；输入的是float，要用%f
// printf：输出的是double，要用%f；输出的是int，要用%d；输出的是char，要用%c；输出的是字符串，要用%s；输出的是float，要用%f(double和float都可以用%f)
// 中文符号不要出现，很难肉眼看出，一定要注意！特别还有一些空格，在vscode里可以看出来       
//5/2和5/2.0是不一样的，前者是int/int，后者是int/double，前者输出2，后者输出2.5，不要以为double x=5/2就是2.5，这里的5/2是int/int，所以x=(double)2=2.000000