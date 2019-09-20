#include <vector>
#include <iostream>

using namespace std;

auto _= [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), cur(0);
        for (int i = 1; i < len; i++){
            if (nums[i] != nums[cur]){
                nums[++cur] = nums[i];
            }
        }
        return cur+1;
    }
};