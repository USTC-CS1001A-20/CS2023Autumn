#define _CRT_SECURE_NO_WARNINGS
/*
【问题描述】对一个单链表部分区域进行反转。要求编写函数输入链表；编写函数对链表部分区域进行反转；编写函数输出链表。注意：
           仅允许使用malloc为n个结点指针分配内存以存储链表数据元素，其中n为第一行数据个数，不允许额外的malloc或者声明
           数组空间；仅允许操作结点指针，不允许更改结点数据元素如交换两个结点的数据元素；实现上述三个函数。
【输入形式】第一行若干个整数为链表数据元素，中间以空格隔开。第二行正整数i和j，表示将链表从第i个结点到第j个结点进行反转，中间以空格隔开。
【输出形式】若干个整数表示反转后的链表数据元素排列，中间以空格隔开。
【样例输入】
1 2 3 4 5
2 4
【样例输出】
1 4 3 2 5
*/
#include <stdio.h>
#include <stdlib.h>
//#include <windows.h>

struct num {
    int sum;
    struct num* next;
};
struct num* head, * tail, * p, * q, * r, * s;
//输入
void create() {
    p = (struct num*)malloc(sizeof(struct num));
    head = tail = p;
    char a;
    p->sum = 0;
    while (1) {
        a = getchar();
        if (a <= '9' && a >= '0') {
            p->sum = p->sum * 10 + (a - '0');
        }
        else if (a == ' ') {
            tail->next = p;
            tail = p;
            p = (struct num*)malloc(sizeof(struct num));
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
void handle1(int j) {
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
void handle2(int i, int j) {
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