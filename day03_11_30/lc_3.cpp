//
// Created by Lanture on 2022/11/30.
//
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> map;
        int left = 0, right =0;
        int n = s.length(), res = 0;
        while(right<n){
            char tmp = s[right++];
            if(map.count(tmp)!=0){
                left = max(left,map[tmp]+1);
            }
            res = max(res,right-left);
            map[tmp] = right-1;
        }
        return res;
    }
};