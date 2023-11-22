#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main(){
    int a[200] = {0};
    int b[200] = {0};
    int result[400] = {0};
    std::string s1(""), s2("");
    cin >> s1 >> s2;
    int a_len = s1.length();
    int b_len = s2.length();
    int i = a_len - 1;
    for (auto &temp : s1){
        a[i--] = temp - '0';
    }
    i = b_len - 1;
    for (auto &temp : s2){
        b[i--] = temp - '0';
    }
    // result = a * b;
    for (int i = 0; i < a_len; i++){
        for (int j = 0; j < b_len; j++){
            result[i + j] += a[i] * b[j];
        }
    }
    // 进位
    for (int i = 0; i < a_len + b_len; i++){
        if (result[i] >= 10){
            result[i + 1] += result[i] / 10;
            result[i] %= 10;
        }
    }
    // 输出
    int flag = 0;
    stringstream ss;
    for (int i = a_len + b_len; i >= 0; i--){
        if (result[i] != 0){
            flag = 1;
        }
        if (flag){
            ss << result[i];
        }
    }
    if(ss.str().length() == 0)
        cout << 0 << endl;
    else
        cout << ss.str() << endl;
    return 0;
}