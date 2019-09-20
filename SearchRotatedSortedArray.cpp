#include <vector>

using namespace std;


class Solution {
    int BinarySearch(vector<int>& nums, int target, int start, int end){
        if(start > end) return -1;

        int mid = start + (end-start)/2;

        if (target == nums[mid]) return mid;

        if ((target >= nums[start] && target < nums[mid]) || (target < nums[mid] && nums[mid] < nums[start]) || (nums[mid] < nums[start] && target >= nums[start])){
            return BinarySearch(nums, target, start, mid-1);
        }else{
            return BinarySearch(nums, target, mid+1, end);
        }

    }
public:
    int search(vector<int>& nums, int target) {
        int len(nums.size());
        if (len == 0) return -1;

        return BinarySearch(nums, target, 0, len-1);
    }
};