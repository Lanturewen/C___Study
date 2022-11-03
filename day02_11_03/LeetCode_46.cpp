//
// Created by Lanture on 2022/11/3.
//
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> track;
    vector<vector<int>> permute(vector<int>& nums) {
        bool used[nums.size()];
        memset(used,sizeof(used),0);//必须使用memset初始化,(首地址,大小,初始值); 导入cstring;
//        vector<bool> used(nums.size(), false); // 可以使用vector 赋予初始值.
        backtrack(nums,used);
        return res;
    }

    void backtrack (vector<int>& nums,  bool used[]) {
        if(track.size()==nums.size()){
            res.push_back(track);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,used);
            used[i] = false;
            track.pop_back();
        }
    }
};