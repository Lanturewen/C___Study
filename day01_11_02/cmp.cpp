//
// Created by Lanture on 2022/11/2.
//

#include <algorithm>
#include <iostream>
using namespace std;
bool cmp(int a, int b){
    return b-a<0;
}
int main01(){
    int nums[4]={1,3,5,2};
    sort(nums,nums+4,cmp);
    for(int i:nums){
        cout<<i<<" ";
    }
}