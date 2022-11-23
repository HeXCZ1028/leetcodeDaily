/**
 * @file solution.cpp
 * @author HeXCZ1028 (heisright@163.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include<vector>
#include<map>
#include<string>
using namespace std;

// #1: https://leetcode.cn/problems/number-of-unequal-triplets-in-array/
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        map<int,int> numCount;
        for(auto val:nums){
            numCount[val]++;
        }
        int lessNum=0,equalNum=0,greatNum=nums.size();
        int result=0;
        for(auto it=numCount.begin();it!=numCount.end();++it){

            equalNum=it->second;
            greatNum-=equalNum;

            result+=lessNum*equalNum*greatNum;

            lessNum+=equalNum;
        }
        return result;
    }
};

// #2: https://leetcode.cn/problems/closest-nodes-queries-in-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<int> nums;
        inOderTraversal(root,nums);

        vector<vector<int>> result;
        for(auto val:queries){
            int first=upper_bound(nums,val);
            int second=lower_bound(nums,val);
            result.emplace_back(vector<int>{first,second});
        }
        return result;
    }
    void inOderTraversal(TreeNode* root,vector<int> &nums){
        if(root==nullptr)
            return ;
        if(root->left!=nullptr){
            inOderTraversal(root->left,nums);
        }
        nums.push_back(root->val);
        if(root->right!=nullptr){
            inOderTraversal(root->right,nums);
        }
        return ;
    }
    // find min VAL that greater than or equal to TARGET,if not exist return -1.
    int lower_bound(const vector<int> &nums,int target){
        int begin=0,end=nums.size();
        
        while(begin<end){
            int mid=begin+(end-begin)/2;
            if(nums[mid]<target)
                begin=mid+1;
            else
                end=mid;
        }
        // 此时,跳出循环后,begin和end指向同一个位置,都指向第一个大于等于target的位置
        // 若数组中所有元素都比target小,则begin=nums.size()
        
        if(begin!=nums.size())
            return nums[begin];
        else
            return -1;
    }
    // find max VAL that less than or equal to TARGET, if not exist return -1.
    int upper_bound(const vector<int> &nums,int target){
        int begin=0,end=nums.size();
        while(begin<end){
            int mid=begin+(end-begin)/2;
            if(nums[mid]<=target)
                begin=mid+1;
            else
                end=mid;
        }
        // 此时,跳出循环后,begin和end指向同一个位置,都指向第一个大于target的位置
        // 若数组中所有元素都大于target,则begin=0
        
        if(begin>0)
            return nums[begin-1];
        else
            return -1;
    }
};

// #3: https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/
class Solution {
public:
    map<int,vector<int>> graphs;
    long long result;
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        for(auto &v:roads){
            graphs[v[0]].push_back(v[1]);
            graphs[v[1]].push_back(v[0]);
        }
        result=0;
        dfs(0,-1,seats);

        return result;

    }
    long long dfs(int pos,int pre,int seats){
        auto &vec=graphs[pos];
        long long subNum=1;
        for(auto node :vec){
            if(node==pre)
                continue;
            long long tmp=dfs(node,pos,seats);
            subNum+=tmp;
            long long s=tmp % seats;
            result+=s==0? tmp/seats:tmp/seats+1;
        }
        return subNum;
    }
};

// #4: https://leetcode.cn/problems/number-of-beautiful-partitions/
class Solution {
public:
    int beautifulPartitions(string s, int k, int minLength) {
        // TODO:
    }
};