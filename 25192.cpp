#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string>chat;
    string input;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> input;
        if(input == "ENTER")
        {
            chat.clear();
        } 
        else
        {
            if(chat.insert(input).second) count++;
        }
    }
    cout << count;
}