#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

// 1
class Solution {
public:
   string finalString(string s) {
       string result;
       for(char c:s){
           if(c=='i'){
               std::reverse(result.begin(), result.end());
           }
           else{
               result.push_back(c);
           }
       }
       return result;
   }
};

// 
class Solution {
public:
    bool canSplitArray(vector<int>& nums, int m) {
        // 特殊情况,优先考虑
        if(nums.size()<=2)
            return true;
        for(int i=0;i<nums.size()-1;++i){
            if(nums[i]+nums[i+1]>=m){
                return true;
            }
        }
        return false;
    }
};
