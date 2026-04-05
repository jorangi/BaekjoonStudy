#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    deque<int> queue_stack; //원형큐면 앞뒤 삽입으로 편하다

    //queuestack 길이
    int n;
    cin >> n;

    vector<int> arr_IsStack(n);
    //큐인지 스택인지
    for(int i = 0; i < n; i++) cin >> arr_IsStack[i];

    // 수열 A 입력, 스택이면 안넣는다.
    // pop을 큐의 역순으로 한다 -> 앞으로 넣는다
    for(int i = 0; i < n; i++)
    {
        int elementA;
        cin >> elementA;
        if(arr_IsStack[i]) continue; //사실 STACK은 1이라서 이렇게 처리해도 된다
        queue_stack.push_back(elementA);
    }

    //삽입할 수열 길이
    int m;
    cin >> m;

    //수열 B는 뒤로 넣는다
    for(int i = 0; i < m; i++)
    {
        int elementB;
        cin >> elementB;
        queue_stack.push_front(elementB);
        cout << queue_stack.back() << ' ';
        queue_stack.pop_back();
    }
}