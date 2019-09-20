#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int size = nums.size(), target = 0, l = 0, r = 0, sum = 0;
        vector<vector<int>> res;

        for (int i = 0; i < size-2; i++){
            target = -nums[i];
            l = i+1;
            r = size-1;
            while (l < r){
                sum = nums[l] + nums[r];
                if (sum < target){
                    l++;
                }else if(sum > target){
                    r--;
                }else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    while(l<r && nums[l+1] == nums[l]) l++;
                    while(l<r && nums[r-1] == nums[r]) r--;
                    l++;
                    r--;
                }
            }
            while(i<size-2 && nums[i+1] == nums[i]) i++;
        }
        return res;

    }
};