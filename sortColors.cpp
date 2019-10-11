#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n1(0), n2(0), cur(nums.size()-1);
        for (auto num:nums){
            if (num == 1){
                n1++;
            }else if (num == 2){
                n2++;
            }
        }
        while (n2>0){
            nums[cur--] = 2;
            n2--;
        }
        while(n1>0){
            nums[cur--] = 1;
            n1--;
        }
        while (cur >=0){
            nums[cur--] = 0;
        }
    }
};