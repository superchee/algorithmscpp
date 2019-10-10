
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n(intervals.size()), cur(0);
        vector<vector<int>> ans;

        while (cur < n){
            if (intervals[cur][1] < newInterval[0]){
                ans.push_back(intervals[cur++]);
            }else{
                break;
            }
        }

        ans.push_back(newInterval);

        if (cur == n){
            return ans;
        }

        if (intervals[cur][0] < ans.back()[0]){
            ans.back()[0] = intervals[cur][0];
        }

        while(cur < n){
            if (intervals[cur][0] <= newInterval[1]){
                ans.back()[1] = max(ans.back()[1], intervals[cur++][1]);
            }else{
                break;
            }
        }

        while(cur < n){
            ans.push_back(intervals[cur++]);
        }

        return ans;
    }
};