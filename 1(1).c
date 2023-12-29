#include<stdio.h>
#include<string.h>
#define N_MAX 200
void num_change(int a[], int b[], int c[], int n) {
    for (int i = 1;i <= n;i++) {
        c[a[i]] = b[i];
    }
}
int com[N_MAX * N_MAX][N_MAX + 1];
int main() {
    int n;
    scanf("%d", &n);
    int a[N_MAX + 1] = { 0 };
    int b[N_MAX + 1];
    int c[N_MAX + 1];
    char inp[N_MAX + 1];
    for (int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        b[i] = i;
        c[i] = i;
    }
    int times;
    int flag = 0;
    while (1) {
        scanf("%d", &times);
        if (times == -1) {
            break;
        }
        if (times >= 0 && flag) {
            printf("\n");
            getchar();
        }
        if (times >= 0 && !flag) {
            getchar();   //TODO: bug处
            flag = 1;
        }
        if (times == 0) {
            gets(inp);
            printf("%s", inp);
            continue;
        }
        for (int i = 1;i <= n;i++) {
            b[i] = i;
            c[i] = i;
            com[1][i] = i;
        }
        gets(inp);
        int len = strlen(inp);
        while (len <= n) {
            inp[len] = ' ';
            len++;
        }
        int flag_circle = 0;
        int circle_num = 0;
        int circle_begin = 0;
        for (int i = 1;i <= times;i++) {
            num_change(a, b, c, n);
            memcpy(b, c, N_MAX + 1);
            memcpy(com[i], c, N_MAX + 1);
            for (int j = 1;j < i;j++) {
                if (memcmp(c, com[j], N_MAX + 1) == 0) {
                    circle_begin = j;
                    circle_num = i - j;
                    flag_circle = 1;
                    goto break_two_for;
                }
            }
        }
    break_two_for:
        if (flag_circle) {
            int same_No = circle_begin + (times - circle_begin) % circle_num;
            memcpy(c, com[same_No], N_MAX + 1);
        }
        for (int i = 1;i <= n;i++) {
            printf("%c", inp[c[i] - 1]);
        }
        scanf("%d", &times);
    }
}