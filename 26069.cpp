#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    map<string, bool> isDancing;
    isDancing["ChongChong"] = true;
    int count = 0;
    for(int i = 0; i < n; i++)
    {
        string main;
        string sub;
        cin >> main >> sub;
        if(isDancing[main] || isDancing[sub])
        {
            isDancing[main] = true;
            isDancing[sub] = true;
        }
    }
    for (auto const& [name, dancing] : isDancing)
    {
        if(dancing) count++;
    }
    cout << count;
}