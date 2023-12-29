#include <stdio.h>
#include <string.h>
#include <math.h>
//目前该程序不允许运算过程中出现小于-29900和超过int范围的数，但修改a[]等的数据类型和非数字后面减的30000，可以扩大范围
int compute(int m, int n, char s)
{
    switch(s)
    {
        case '+':
            return m + n;
        case '-':
            return m - n;
        case '*':
            return m * n;
        case '/':
            return m / n;
    }
    return 0;
}
void separate(int a[], int b[], int x, int y)//将a中的x到y位存到b中
{
    int t = 0;
    for (int i = x + 1; i < y; i++)
    {
        b[t++] = a[i];
    }
}
int main()
{
    char a_char[100];
    int i, j = 0, sum = 0, t[5] = {0}, bracket1[5], bracket2[5], matched[5][2], sign[5] = {0};
    int match_length[5], bracket_num, a[100] = {0}, b[100] = {0}, in_bracket[10][30] = {0};
    gets(a_char);
    for (i = 0; a_char[i]; i++)
    {
        a[i] = a_char[i];
    }
    for (i = 0; a_char[i]; i++)
    {
        if (a[i] >= '0' && a[i] <= '9')
        {
            sum += 1;
            a[i] -= '0';
        }
        else
        {
            a[i] -= 30000;
            for (; sum > 1; sum--)
            {
                a[i - 1] += pow(10, (double)(sum - 1)) * a[i - sum];
                a[i - sum] = ' ' - 30000;
            }
            sum = 0;
        }
    }
    for (i = 0; a[i] || a[i + 1]; i++)//这样做是因为字符串内部可能也会出现数字0
    {
        if (a[i] != ' ' - 30000 && a[i] != '=' - 30000)
        {
            b[j++] = a[i];
        }
    }
    for (i = 0; b[i] || b[i + 1]; i++)
    {
        if (b[i] == '(' - 30000)
        {
            bracket1[t[1]++] = i;
        }
        if (b[i] == ')' - 30000)
        {
            bracket2[t[2]++] = i;
        }
    }
    for (i = t[1] - 1; i > -1; i--)
    {
        for (j = 0; j < t[2]; j++)
        {
            if (sign[j] != 1)
            {
                if (bracket1[i] < bracket2[j])
                {
                    matched[t[3]][0] = bracket1[i];
                    matched[t[3]][1] = bracket2[j];
                    match_length[t[3]++] = bracket2[j] - bracket1[i];
                    sign[j] = 1;
                    break;
                }
            }
        }
    }
    bracket_num = t[3];
    for (i = 0; i < bracket_num; i++)
    {
        separate(b, in_bracket[i], matched[i][0], matched[i][1]);
        for (j = 1; in_bracket[i][j] || in_bracket[i][j + 1]; )
        {
            if (in_bracket[i][j] == '*' - 30000 || in_bracket[i][j] == '/' - 30000)
            {
                in_bracket[i][j - 1] = compute(in_bracket[i][j - 1], in_bracket[i][j + 1], in_bracket[i][j] + 30000);
                for (int z = j; in_bracket[i][z]; z++)
                {
                    in_bracket[i][z] = in_bracket[i][z + 2];
                }
                continue;
            }
            j += 2;
        }
        for (j = 1; in_bracket[i][j] || in_bracket[i][j + 1]; )
        {
            if (in_bracket[i][j] == '+' - 30000 || in_bracket[i][j] == '-' - 30000)
            {
                in_bracket[i][j - 1] = compute(in_bracket[i][j - 1], in_bracket[i][j + 1], in_bracket[i][j] + 30000);
                for (int z = j; in_bracket[i][z]; z++)
                {
                    in_bracket[i][z] = in_bracket[i][z + 2];
                }
                continue;
            }
            j += 2;
        }
        b[matched[i][0]] = in_bracket[i][0];
        for (int z = matched[i][0] + 1; b[z] || b[z + 1]; z++)
        {
            b[z] = b[z + match_length[i]];
        }
        for (int z = i + 1; z < 5; z++)
        {
            if (matched[z][1] > matched[i][1])
            {
                matched[z][1] -= match_length[i];
                match_length[z] -= match_length[i];
            }
        }
    }
    for (i = 1; b[i] || b[i + 1]; )
    {
        if (b[i] == '*' - 30000 || b[i] == '/' - 30000)
        {
            b[i - 1] = compute(b[i - 1], b[i + 1], b[i] + 30000);
            for (j = i; b[j] || b[j + 1]; j++)
            {
                b[j] = b[j + 2];
            }
            continue;
        }
        i += 2;
    }
    for (i = 1; b[i] || b[i + 1]; )
    {
        if (b[i] == '+' - 30000 || b[i] == '-' - 30000)
        {
            b[i - 1] = compute(b[i - 1], b[i + 1], b[i] + 30000);
            for (j = i; b[j] || b[j + 1]; j++)
            {
                b[j] = b[j + 2];
            }
            continue;
        }
        i += 2;
    }
    printf("%d", b[0]);
}
