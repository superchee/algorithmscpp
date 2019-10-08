#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

        int maxReach(0), maxPos(0), ans(0);

        for (int i = 0; i < nums.size(); i++){
            if (i > maxReach){
                maxReach = maxPos;
                ans++;
            }
            maxPos = max(maxPos, i + nums[i]);
        }
        

        return ans;      
    }
};

// class Solution {
// public:
//     int jump(vector<int>& nums) {

//         int maxLen(0), maxIdx(0), cur(0), len(nums.size()), ans(0);
        
//         while(cur < len-1){
//             maxLen = 0;
//             maxIdx = cur + nums[cur];
//             if (maxIdx >= len-1) return ++ans;
//             for (int i = 1; i <= nums[cur]; i++){
//                 if (i+nums[cur+i] > maxLen){
//                     maxLen = i+nums[cur+i];
//                     maxIdx = cur+i;
//                 }
//             }
//             cur = maxIdx;
//             ans++;
//         }

//         return ans;      
//     }
// };