#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sum = 0, dis = 0, l = 0, r = 0, len = nums.size(), ans = 0, minimum = INT_MAX;

        for (int i = 0; i < len-2; i++){
            l = i+1;
            r = len-1;
            while(l < r){
                sum = nums[i] + nums[l] + nums[r];
                dis = target - sum;
                if(abs(dis) < minimum){
                    minimum = abs(dis);
                    ans = sum;
                }
                if (dis > 0){
                    l++;
                    while (l<r && nums[l-1] == nums[l]) l++;
                }else if(dis<0){
                    r--;
                    while (l<r && nums[r+1] == nums[r]) r--;
                }else{
                    return ans;
                }
            }
            while (i < len-2 && nums[i+1] == nums[i]) i++;
        }
        return ans;
    }
};