#include<iostream>
using namespace std;

int hashFunc(string s) {
    int vone = (int)s[0] - 48;
    int vtwo = (int)s[1] - 48;

    int d = vtwo - vone;

    if(d < 0) d = d * -2;

    return d;
}

int main() {

    std::cout << hashFunc("90");
    return 0;
}