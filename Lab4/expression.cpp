#include <iostream>
#include <vector>
#include <cstring>

int main(){
    char a[100] = "";
    std::cin >> a;
    std::vector<std::string> split;
    char *p = strtok(a, " ");
    while (p != nullptr){
        split.push_back(strtok(a, " "));
        p = strtok(nullptr, " ");
    }
}