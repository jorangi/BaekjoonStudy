#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

int solution(int a, int b) {
    int aLen = 0;
    int bLen = 0;
    int _a = a;
    int _b = b;
    while(_a)
    {
        _a/=10;
        aLen++;
    }
    while(_b)
    {
        _b/=10;
        bLen++;
    }
    int result1 = a*pow(10, bLen) + b;
    int result2 = b*pow(10, aLen) + a;
    return result1 > result2 ? result1 : result2;
}

int main(void)
{
    cout << solution(9, 91);
}