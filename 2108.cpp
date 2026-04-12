#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 0;
    cin >> n;

    vector<int> v(n);
    map<int, int> freq;
    double sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
        sum += v[i];
        freq[v[i]]++;
    }
    sort(v.begin(), v.end());

    //평균값
    int avg = round(sum / n);
    if(avg == -0) avg = 0;
    
    //중앙값
    int median = v[n/2];

    vector<pair<int, int>> most;
    int max_freq = 0;
    for(auto const& [num, count]: freq)
    {
        if(count > max_freq)
        {
            max_freq = count;
            most.clear();
            most.push_back({num, count});
        }
        else if(count == max_freq)
        {
            most.push_back({num, count});
        }
    }
    int mode = (most.size() > 1) ? most[1].first : most[0].first;
    int range = v[n-1] - v[0];

    cout << avg << '\n' << median << '\n' << mode << '\n' << range << '\n';
}