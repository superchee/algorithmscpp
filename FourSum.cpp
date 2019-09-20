#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int sum(0), len = nums.size(), l(0), r(0), temp(0);
        vector<vector<int>> vecAns;

        sort(nums.begin(), nums.end());
        
        if (len<4) return vecAns;

        for (int i = 0; i < len-3; i++){
            if (nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
            if (nums[i]+nums[len-3]+nums[len-2]+nums[len-1]<target) continue;
            for (int j = i+1; j < len-2; j++){
                if (nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
                if (nums[i]+nums[j]+nums[len-2]+nums[len-1] <target) continue;
                temp = nums[i]+ nums[j];
                l = j+1;
                r = len-1;
                while(l < r){
                    sum = temp + nums[l] + nums[r];
                    if (sum < target) l++;
                    else if (sum > target) r--;
                    else {
                        vecAns.push_back({nums[i], nums[j], nums[l], nums[r]});
                        while (l < r && nums[l+1] == nums[l]) l++;
                        while (l < r && nums[r-1] == nums[r]) r--;
                        l++;
                        r--;
                    }
                }
                while ( j < len-2 && nums[j+1] == nums[j]) j++;
            }
            while (i < len -3 && nums[i+1] == nums[i]) i++;
        }
        return vecAns;
    }
};