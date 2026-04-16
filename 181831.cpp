#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> arr) {
    int answer = 1;
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            if(arr[i][j] != arr[j][i])
            {
                answer = 0;
                break;
            }
        }
    }
    return answer;
}

int main()
{
    vector<vector<int>> arr = {{5, 192, 33}, {192, 72, 95}, {33, 95, 999}};
    cout << solution(arr);
}