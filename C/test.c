#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

struct num {
    int sum;
    struct num *next;
};
struct num *head, *tail, *p, *q, *r, *s;
//输入
void create() {
    p = (struct num *)malloc(sizeof(struct num));
    head = tail = p;
    char a;
    p->sum = 0;
    while (1) {
        a = getchar();
        if (a <= '9' && a >= '0') {
            p->sum = p->sum * 10  + (a - '0');
        }
        else if (a == ' ') {
            tail->next = p;
            tail = p;
            p = (struct num *)malloc(sizeof(struct num));
        }
        else if (a == '\n') {
            tail->next = p;
            tail = p;
            tail->next = NULL;
            break;
        }
    }
}
//反转
//从头开始
void handle1 (int j) {
    int sum = 0;
    while (sum <= j - 1) {
        q = r = head;
        for (int i = 0; i < j; i++) {
            if (r->next != NULL) {
                r = r->next;
            }
        }
        head = q->next;
        q->next = r->next;
        r->next = q;
        sum++;
    }
}
//不是从头开始
void handle2 (int i, int j) {
    int sum = 0;
    s = head;
    for (int k = 1; k <= i - 2; k++) {
        if (s->next != NULL) {
            s = s->next;
        }
    }
    while (sum <= j - i) {
        r = q = s->next;
        for (int k = 1; k <= j - i; k++) {
            if (r->next != NULL) {
                r = r->next;
            }
        }
        s->next = q->next;
        q->next = r->next;
        r->next = q;
        sum++;
    }
}
//输出
void shuchu() {
    p = head;
    while (p != NULL) {
        printf("%d ", p->sum);
        p = p->next;
    }
}

int main() {
    create();
    //反转
    int i, j;//反转区间
    scanf("%d%d", &i, &j);
    if (i == 1) {
        handle1(j);
    }
    else if (i != 1) {
        handle2(i, j);
    }
    shuchu();
//    system("pause");
    return 0;
}