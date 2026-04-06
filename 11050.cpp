#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[11];
    int n;
    int k;
    cin >> n >> k;

    arr[0] = 1;
    int result = 1;
    for(int i = 1; i <= n; i++)
    {
        result *= i;
        arr[i] = result;
    }
    cout << arr[n] / (arr[k] * arr[n-k]);
}