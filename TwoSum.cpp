#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    vector<int> twosum(vector<int>& nums, int target){
        unordered_map<int, int> hashmap;
        int nSize = nums.size(), nfind = 0;
        vector<int> vecAns;
        for (int i = 0; i < nSize; i++){
            nfind = target - nums[i];
            if (hashmap.find(nfind) != hashmap.end()){
                vecAns.push_back(hashmap[nfind]);
                vecAns.push_back(i);
                break;
            }else{
                hashmap[nums[i]]=i;
            }
        }
        return vecAns;
    }
};

/*** faster 
bool cmp(int* x, int* y){
        return *x < *y;
    }
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int nStart = 0, nEnd = nums.size()-1, sum = 0;
        vector<int*> vecp;
        for (int i = 0; i < nums.size(); i++){
            vecp.push_back(&nums[i]);
        }


        sort(vecp.begin(), vecp.end(), cmp);
        vector<int> vecAns;
        while(nStart < nEnd){
            sum = *vecp[nStart] + *vecp[nEnd];
            if (sum < target){
                nStart++;
            }else if(sum > target){
                nEnd--;
            }else{
                vecAns.push_back(vecp[nStart] - &nums[0]);
                vecAns.push_back(vecp[nEnd] - &nums[0]);
                break;
            }
        }
        return vecAns;
    }
};
***/