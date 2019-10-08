#include <vector>

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int len(prices.size()), buy(0), sell(0), ans(0);

        for (int i = 0; i < len; i++){
            for (int j = i+1; j < len; j++){
                if (prices[i] > prices[j]){
                    ans = ans + prices[j-1] - prices[i];
                    break;
                } 
                if (j == len - 1){
                    ans = ans + prices[j] - prices[i];
                    break;
                }
            }
        }
        return ans;
    }
};