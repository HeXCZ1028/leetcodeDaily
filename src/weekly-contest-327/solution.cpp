#include <queue>
#include <map>
using namespace std;
// #1
class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int negCount = 0, posCount = 0;
        for (auto val : nums)
        {
            if (val < 0)
                negCount++;
            if (val > 0)
                posCount++;
        }
        return max(negCount, posCount);
    }
};

// #2
class Solution
{
public:
    long long maxKelements(vector<int> &nums, int k)
    {
        priority_queue<int> pri;
        for (auto val : nums)
        {
            pri.push(val);
        }
        int i = 0;
        long long res = 0;
        while (i < k)
        {
            auto val = pri.top();
            res += val;
            pri.pop();
            int valIn = ceil(val);
            pri.push(valIn);
            i++;
        }
        return res;
    }
    int ceil(int val)
    {
        int v = val / 3;
        int s = val % 3;
        if (s > 0)
            return v + 1;
        else
            return v;
    }
};
