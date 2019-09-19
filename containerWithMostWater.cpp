#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int nStart = 0, nEnd = height.size()-1, nMax = 0, nWater = 0;
        while(nStart < nEnd){
            nWater = height[nStart] < height[nEnd] ? (nEnd-nStart)*height[nStart++]:(nEnd-nStart)*height[nEnd--];
            nMax = max(nWater,nMax);
        }
        return nMax;
    }
};

static const auto io_sync_off = []()
{
    // turn off sync
    std::ios::sync_with_stdio(false);
    // untie in/out streams
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();