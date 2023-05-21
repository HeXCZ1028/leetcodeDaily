#include <iostream>
#include <vector>
#include <unordered_map>
#include<set>
#include <map>

using namespace std;

// 1 直接暴力
class Solution {
public:
   int minLength(string s) {
       while (hasABorCD(s)){
           if(s.find("AB")!=s.size()){
               int start=s.find("AB");
               if(start!=-1) {
                   if (start == 0) {
                       s = s.substr(start + 2);
                   } else {
                       s = s.substr(0, start) + s.substr(start + 2);
                   }
               }
           }
           if(s.find("CD")!=s.size()){
               int start=s.find("CD");
               if(start!=-1) {
                   if (start == 0) {
                       s = s.substr(start + 2);
                   } else {
                       s = s.substr(0, start) + s.substr(start + 2);
                   }
               }
           }
       }
       return s.size();
   }
   bool hasABorCD(string s){
       if(s.find("AB")!=-1|| s.find("CD")!=-1){
           return true;
       }
       else{
           return false;
       }
   }
};

// 简单模拟
class Solution {
public:
   string makeSmallestPalindrome(string s) {
       int i=0,j=s.size()-1;
       int count=0;
       while(i<=j){
           if(s[i]!=s[j]){
               count++;
               if(s[i]-'a'>s[j]-'a'){
                   s[i]=s[j];
               }
               else{
                   s[j]=s[i];
               }
           }
           i++;
           j--;
       }
       return s;
   }
};

// 对于每个i(1<=i<=n) 回溯(su)判断i * i 的十进制表示的字符串可以分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 i
class Solution {
public:
    vector<vector<int>> value;
    int ans=0;
    int result=-1;
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;++i){
            ans=0;
            result=-1;
            string s=to_string(i*i);
            value.assign(s.size(), vector<int>(s.size(),-1));
            dfs(s,0,i);
            if(result==i){
                sum+=i*i;
                result=-1;
            }
        }
        return sum;
    }
    // 记忆化搜索中，f[i][j] = -1 表示未搜索，否则表示值
    int intNumber(const string& s, int i, int j){
        if(value[i][j]==-1){
            int val=0;
            for(int k=i;k<=j;++k){
                val=val*10+s[k]-'0';
            }
            return value[i][j]=val;
        }
        else{
            return value[i][j];
        }
    }
    void dfs(const string& s, int i,const int number) {
        if (i ==s.size() && ans==number) {
            result=number;
            return ;
        }
        for (int j = i; j < s.size(); ++j) {
            if (intNumber(s,i,j)<=number) {
                if(ans+ intNumber(s,i,j)<=number){
                    ans+= intNumber(s,i,j);
                    dfs(s, j + 1,number);
                    ans-= intNumber(s,i,j);
                }
            }
        }
    }
};