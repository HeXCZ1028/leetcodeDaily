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
    int furthestDistanceFromOrigin(string moves) {
        int count_R=0,count_L=0,count_underline=0;
        for(int i=0;i<moves.size();++i){
            if(moves[i]=='R'){
                count_R++;
            }
            else if(moves[i]=='L'){
                count_L++;
            }
            else{
                count_underline++;
            }
        }
        return max(count_R,count_L)-min(count_R,count_L)+count_underline;
    }
};

// 2
class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        int i=0;
        long long result=0;
        set<int> visited;
        int val=1;
        while(i<n){
            // 不在
            if(visited.find(target-val)==visited.end()){
                result+=val;
                visited.insert(val);
                i++;
            }
            val++;
        }
        return result;
    }
};


// 3 
// 代码来源：https://leetcode.cn/problems/minimum-operations-to-form-subsequence-with-target-sum/solutions/2413451/fen-lei-tao-lun-by-tsreaper-n5t7/
class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        // 排除无解的情况
        long long sm = 0;
        for (int x : nums) sm += x;
        if (sm < target) return -1;

        // nums 从大到小排序
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        int ans = 0;
        // t 表示比当前二进制位小的所有数之和
        long long t = 0;
        for (int i = 0; i <= 30; i++) if (target >> i & 1) {
            int x = 1 << i;

            // 不断把比当前二进制位小的数加到 t 里
            while (!nums.empty() && nums.back() < x && t < x) t += nums.back(), nums.pop_back();
            // 比当前二进制位小的数之和已经大于等于当前二进制位，这一位不用操作
            if (t >= x) t -= x;
            // 刚好找到需要的数，也不用操作
            else if (nums.back() == x) nums.pop_back();
            else {
                // 看下一个更大的数，用它拆出当前二进制位
                // 为什么直接取 nums.back() 就好？看下一条注释
                int y = nums.back(); nums.pop_back();
                while (y > x) {
                    y >>= 1;
                    // 注意：只有这里会往 nums 的尾部添加数
                    // 由于添加的数都小于原来的尾部，而且是以递减的顺序添加的
                    // 所以 nums 递减的性质不改变
                    nums.push_back(y);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// 4 
// 代码来源： https://leetcode.cn/problems/maximize-value-of-function-in-a-ball-passing-game/solutions/2413322/bei-zeng-suan-fa-ye-shi-yi-ge-tao-lu-ti-6ilak/

// 倍增算法
class Solution {
public:
    long long getMaxFunctionValue(vector<int>& a, long long k) {
        int n = a.size();
        int f[n][36];
        long long w[n][36];
        for(int i = 0; i < n; ++i) {
            f[i][0] = a[i];
            w[i][0] = i;
        }
        for(int j = 1; j < 36; ++j) {
            for(int i = 0; i < n; ++i) {
                f[i][j] = f[f[i][j-1]][j-1];
                w[i][j] = w[i][j-1] + w[f[i][j-1]][j-1];
            }
        }
        long long res = 0;
        for(int i = 0; i < n; ++i) {
            long long cur = 0;
            int pos = i;
            for(int j = 0; j < 36; ++j) {
                if((k >> j) & 1) {
                    cur += w[pos][j];
                    pos = f[pos][j];
                }
            }
            res = max(res, cur + pos);
        }
        return res;
    }
};