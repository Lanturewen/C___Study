//
// Created by Lanture on 2022/11/3.
//
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int> > dp(n+1,vector<int>(n+1,0));//dp[i][j]表示s[i-j]中中最长的回文子序列的长度.
        for(int i=1;i<=n;i++){
            dp[i][i] = 1;
        }
        for(int i=n;i>=1;i--){
            for(int j=i+1;j<=n;j++){
                if(s[i-1]==s[j-1]){ // 注意这里写"="不会报错的.
                    dp[i][j] = dp[i+1][j-1]+2;
                }else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     for(int j=1;j<=n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[1][n];
    }
};