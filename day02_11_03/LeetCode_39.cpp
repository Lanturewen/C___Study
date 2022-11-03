//
// Created by Lanture on 2022/11/3.
//
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0);
        return res;
    }
    void backtrack(vector<int>& candidates, int target,int start){
        if(target==0){
            res.push_back(track);
        }
        for(int i=start; i<candidates.size();i++){
            if(target<0){
                continue;
            }
            track.push_back(candidates[i]);
            target-=candidates[i];
            backtrack(candidates,target,i);
            target+=candidates[i];
            track.pop_back();
        }
    }
};