//
// Created by Lanture on 2022/11/2.
//
#include <vector>
#include <unordered_set>
using namespace  std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> uset;
        unordered_set<int> res;
        for(int n:nums1){
            uset.insert(n);//insert()而不是push_back();
        }
        for(int n:nums2){
            auto it = uset.find(n);
            if(it!=uset.end()){ //是uset.end()而不是nums2.end();
                res.insert(n);
            }
        }
        return vector<int>(res.begin(),res.end());//set转vector.
    }
};
