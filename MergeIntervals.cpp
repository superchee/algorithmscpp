#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        int len(intervals.size()), nStart(0), nEnd(0), cur(0);

        if (len <= 1) return intervals;
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] < b[0]) return true;
            // if (a[0] == b[0]) return a[1] <= b[1];
            return false;
        });

        // for (auto interval:intervals){
        //     if (ans.size() == 0 || ans.back()[1] < interval[0]){
        //         ans.push_back({interval[0],interval[1]});
        //     }else{
        //         ans.back()[1] = max(ans.back()[1], interval[1]);
        //     }
        // }

        while(cur < len){
            nStart = intervals[cur][0];
            nEnd = intervals[cur][1];
            while(cur<len-1 && nEnd >= intervals[cur+1][0]){
                cur++;
                if (nEnd < intervals[cur][1]){
                    nEnd = intervals[cur][1];
                }
            }
            ans.push_back({nStart,nEnd});
            cur++;
        }

        return ans;


    }
};