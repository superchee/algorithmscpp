#include <vector>

using namespace std;


class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int leftMost(nums.size()-1);
        for (int i = nums.size()-2; i >=0; i--){
            if (nums[i] + i >= leftMost){
                leftMost = i;
            }
        }

        return leftMost == 0;
    }
};

//time limit exceeded

// class Solution {
//     bool dfs(vector<int>& nums, int idx, int end){
//         if (idx >= end) return true;
//         for (int i = nums[idx]; i >= 1; i--){
//             if(dfs(nums, idx+i, end)) return true;
//         }
//         return false;
//     }
// public:
//     bool canJump(vector<int>& nums) {
//         int len(nums.size());

//         return dfs(nums, 0, len-1);
//     }
// };