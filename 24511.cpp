#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //문제대로 구현시, 큐는 0번, 스택은 1번 할당하여 전부 집어넣음
    //스택은 그냥 무시하면 될 것 같긴 한데 일단은 정석으로 구현해볼것

    //queue와 stack을 구분하는 enum -> enum은 cast해야하니 그냥 상수로
    //노드 길이는 최대 10만
    // enum class QUEUE_STACK
    // {
    //     QUEUE=0,
    //     STACK=1
    // };
    const int QUEUE = 0;
    const int STACK = 1;
    const int NODE_LENGTH = 100000;
    bool arr_IsStack[NODE_LENGTH];
    int queue_stack[NODE_LENGTH];

    //queuestack 길이
    int n;
    cin >> n;

    //큐인지 스택인지
    for(int i = 0; i < n; i++)
    {
        int isStack;
        cin >> isStack;
        arr_IsStack[i] = isStack;
    }

    // 수열 A 입력
    for(int i = 0; i < n; i++)
    {
        int elementA;
        cin >> elementA;
        queue_stack[i] = elementA;
    }

    //삽입할 수열 길이
    int m;
    cin >> m;

    //10만 사이즈를 2중 반복돌리는것은 무거움
    for(int i = 0; i < m; i++)
    {
        int elementB;
        cin >> elementB;
        for(int j = 0; j < n; j++)
        {
            //스택이면 그냥 넘김
            if(arr_IsStack[j] == STACK) continue;

            //큐면 입력값과 교환
            int temp = elementB;
            elementB = queue_stack[j];
            queue_stack[j] = temp;
        }
        cout << elementB << ' ';
    }
}