#include <vector>

using namespace std;


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n(nums.size());

        int len(1<<n);

        vector<vector<int>> ans;
        vector<int> temp;

        for (int i = 0; i < len; i++){
            temp.clear();
            for(int j = 0; j < n; j++){
                if (i&(1<<j)) temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};