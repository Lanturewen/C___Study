//
// Created by Lanture on 2022/11/2.
//
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        //不写等于{0}会随机初始化
        int records[26]={0};
        for(char c:s){
            records[c-'a']++;
        }
        for(char c:t){
            records[c-'a']--;
        }
        for(int n : records){
            if(n!=0) return false;
        }
        return true;
    }
};

int main(){
    string s = "rat";
    string t = "art";
    Solution so;
    cout<<so.isAnagram(s,t);
    return 0;
}