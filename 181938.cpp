#include <string>
#include <iostream>

using namespace std;

int solution(int a, int b) {
    string _a = to_string(a);
    string _b = to_string(b);
    int result1 = stoi(_a + _b);
    int result2 = 2 * a * b;
    return result1 > result2 ? result1 : result2;
}

int main()
{
    cout << solution(91, 2);
}