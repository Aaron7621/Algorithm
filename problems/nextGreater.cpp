#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// 2 3 4 1 3
// 2 3 4
// 
vector<int> nextGreaterElements(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; -- i)
    {
        while (!st.empty() && nums[i] >= st.top()) st.pop();
        if (!st.empty()) ans[i] = st.top();
        st.push(nums[i]);
    }

    for (int i = n - 1; i >= 0; -- i)
    {
        if (ans[i] != -1) continue;
        while (!st.empty() && nums[i] >= st.top()) st.pop();
        if (!st.empty()) ans[i] = st.top();
        st.push(nums[i]);
    }
    return ans;
}

int main()
{
    vector<int> t = {4,3,5,7,6};
    vector<int> ans = nextGreaterElements(t);

    for (auto &i : ans) cout << i << " ";
    puts(""); 
    return 0;

}