/*
3. Longest Substring Without Repeating Characters
*/

#include<iostream>
#include<unordered_map>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    unordered_map<char, int> um;
    int n = s.size(), ans = 0;
    for (int i = 0, j = 0; i < n; ++ i)
    {
        ++ um[s[i]];
        while (um[s[i]] > 1) -- um[s[j ++]];
        ans = max(ans, i - j + 1);
    }
    
    cout << ans << endl;
    return 0;
}