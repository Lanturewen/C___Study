//
// Created by Lanture Wen on 2022/11/3.
//
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    struct cmp{
        bool operator() (pair<int, int> &p1, pair<int, int> &p2){
            //重载函数调用符号(), 结构体如果里面元素是结构体本身就是重载<,并且pq里面放的是结构体
            if(p1.second != p2.second){ //不是->
                return p1.second-p2.second>0;
            }else{
                return true;
            }
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        for(int n:nums){
            umap[n]++;
        }
        auto it = umap.begin();
        priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;//注意第二个元素是vector
        while(it!=umap.end()){
            if(pq.size()<k || it->second > pq.top().second){
                pair<int,int> tmp(it->first,it->second);
                pq.push(tmp);
            }
            if(pq.size()>k){
                pq.pop();
            }
            it++;
        }
        vector<int> res;
        while(pq.size()!=0){
            pair<int,int> tmp = pq.top();
            // cout<<tmp.first<<" ";
            pq.pop();
            res.push_back(tmp.first);
        }
        return res;
    }
};