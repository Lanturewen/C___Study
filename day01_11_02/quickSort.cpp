//
// Created by Lanture on 2022/11/2.
//

#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    void mySort(vector<int>& nums,int s, int e){
        if(s>=e) return;
        int partition = quicksort(nums,s,e);
        mySort(nums,s,partition-1);
        mySort(nums,partition+1,e);
    }

    int quicksort(vector<int>& nums,int left, int right){
        int pivot = nums[left];
        int i=left, j = right;

        while(i<j){
            while(i<j && nums[j]>=pivot){
                j--;
            }
            nums[i] = nums[j];
            while(i<j && nums[i]<=pivot){
                i++;
            }
            nums[j] = nums[i];
        }
        nums[i]=pivot;
        return i;
    }
};

int main1(){
    solution s;
    vector<int> vec = {1,3,4,5,2,1};
    s.mySort(vec,0,vec.size()-1);
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
}


