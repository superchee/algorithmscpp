#include <vector>
#include <unordered_map>

using namespace std;



class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count(0), ans(0);
        for (auto num:nums){
            if (count == 0){
                ans = num;
                count = 1;
            }else{
                count += num == ans? 1:-1;   
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         unordered_map<int, int> ansMap;
//         int n(nums.size());
//         for (auto num:nums){
//             if (ansMap.find(num) == ansMap.end()){
//                 ansMap[num] = 1;
//             }else{
//                 ansMap[num]++;
//             }
//             if (ansMap[num] > (n/2)) return num;
//         }
        
//         return 0;
//     }
// };