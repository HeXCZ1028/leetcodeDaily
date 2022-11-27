/**
 * @file solution.cpp
 * @author HeXCZ1028 (heisright@163.com)
 * @brief 
 * @version 0.1
 * @date 2022-11-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// #1: https://leetcode.cn/contest/weekly-contest-321/problems/find-the-pivot-integer/
class Solution {
public:
    int pivotInteger(int n) {
        int s=0;
        for(int i=1;i<=n;++i){
            s+=i;
        }
        int count=0;
        for(int i=1;i<=n;++i){
            count+=i;
            if(count==s-count+i){
                return i;
            }
        }
        return -1;
    }
};

// #2: https://leetcode.cn/contest/weekly-contest-321/problems/append-characters-to-string-to-make-subsequence/
class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,j=0;
        while(i<s.size() && j<t.size()){
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        return t.size()-j;
    }
};

// #3: https://leetcode.cn/contest/weekly-contest-321/problems/remove-nodes-from-linked-list/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<int> sta;
        ListNode* tmp=head;
        while(tmp!=nullptr){
            while(!sta.empty() && sta.top()<tmp->val){
                sta.pop();
            }
            sta.push(tmp->val);
            tmp=tmp->next;
        }
        ListNode *result=nullptr;
        while(!sta.empty()){
            ListNode *tmp=new ListNode(sta.top());
            sta.pop();
            
            tmp->next=result;
            result=tmp;
        }
        return result;
    }
};

// #4：https://leetcode.cn/contest/weekly-contest-321/problems/count-subarrays-with-median-k/
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int u;
        for(int i = 0; i < nums.size(); i ++)
        {
            if(nums[i] == k)
            {
                nums[i] = 0;
                u = i;
            }
            else if(nums[i] > k)nums[i] = 1;
            else nums[i] = -1;
        }
        unordered_map<int, int> book;
        int tot = 0, ans = 1;
        for(int i = u - 1; i >= 0; i --)
        {
            tot += nums[i];
            if(tot == 0)ans ++;
            if(tot == 1)ans ++;
            book[tot] ++;
        }
        tot = 0;
        for(int i = u + 1; i < nums.size(); i ++)
        {
            tot += nums[i];
            if(tot == 0)ans ++;
            if(tot == 1)ans ++;
            ans += book[-tot];
            ans += book[1 - tot];
        }
        return ans;
    }
};