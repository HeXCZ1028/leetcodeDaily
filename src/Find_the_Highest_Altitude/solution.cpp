/**
 * @file solution.cpp
 * @author HeXCZ1028 (heisright@163.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-19
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result=0;
        int height=0;
        for(auto val:gain){
            height+=val;
            result=max(result,height);
        }
        return result;
    }
};