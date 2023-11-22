#include <stdio.h>
#include <stdbool.h>

#define MAX 100
#define CHAR_LEGAL (upch && lwch && num)
int main(){
    char password[MAX];
    gets(password);
    bool upch = false, lwch = false, num = false;
    int len = 0;
    for (int i = 0; password[i]; i++, len++){
        if(password[i] >= 'a' && password[i] <= 'z') lwch = true;
        else if(password[i] >= 'A' && password[i] <= 'Z') upch = true;
        else if(password[i] >= '0' && password[i] <= '9') num = true;
    }
    if (!CHAR_LEGAL) putchar('0');
    else if (len < 8 || len > 15) puts("-1");
    else putchar('0');
}