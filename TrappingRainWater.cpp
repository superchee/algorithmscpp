#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans(0), cur(0), size(height.size()), top(0);
        stack<int> st;
        while(cur < size){
            while (!st.empty() && height[cur] > height[st.top()]){
                top = st.top();
                st.pop();
                if (st.empty()) break;
                ans += (min(height[cur], height[st.top()])-height[top])*(cur - st.top()-1);
            }
            st.push(cur++);
        }
        return ans;
    }
};