//
// Created by Lanture on 2022/11/3.
//
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,1);//dp[i]是第i个元素
        dp[1] = 1;
        int res = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<i; j++){
                if(nums[j-1]<nums[i-1] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    res = max(dp[i],res);
                }
            }
        }
        return res;
    }
};