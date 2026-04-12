#include <iostream>

using namespace std;

long long dp[31][31]; //이전의 이항계수문제처럼 풀려면 값이 너무 커져서 초과된다.
int main()
{
    int t;
    cin >> t;


    for(int i = 0; i <= 30; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == 0 || j == i) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        cout << dp[m][n] << '\n';
    }
}