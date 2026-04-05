#include <iostream>
#include <queue>
#include <stack>
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
    queue<int> queue_stack; //결국 큐스택은 스택인 경우 그냥 삽입안한 큐이다.

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
        if(arr_IsStack[i] == STACK) continue;
        queue_stack.push(elementA);
    }
    //큐를 반전해야 하니 스택에 넣었다가 뺴기
    stack<int> temp;
    while(!queue_stack.empty())
    {
        temp.push(queue_stack.front());
        queue_stack.pop();
    }
    while(!temp.empty())
    {
        queue_stack.push(temp.top());
        temp.pop();
    }

    //삽입할 수열 길이
    int m;
    cin >> m;

    //수열 B는 그냥 큐를 넣으면서 출력한다.
    for(int i = 0; i < m; i++)
    {
        int elementB;
        cin >> elementB;
        queue_stack.push(elementB);
        cout << queue_stack.front() << ' ';
        queue_stack.pop();
    }
}