// #1
class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int s=0,bitS=0;
        for(auto v:nums)
        {
            s+=v;
            bitS+=bitSum(v);
        }
        return abs(s-bitS);
    }
    int bitSum(int n)
    {
        int s=0;
        while(n){
            s+=n%10;
            n/=10;
        }
        return s;
    }
};