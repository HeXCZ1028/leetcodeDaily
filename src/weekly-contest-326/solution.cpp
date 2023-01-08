// #1
class Solution {
public:
    int countDigits(int num) {
        int count=0;
        int val=num;
        while(num)
        {
            int n=num%10;
            if(val%n==0)
            {
                count++;
            }
                
            num=num/10;
        }
        return count;
    }
};

// #2
class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        set<int> primerFactor;
        for(int j=0;j<nums.size();++j)
        {
            int i=2;
            int val=nums[j];
            while(i*i<=val)
            {
                if(val%i==0)
                    primerFactor.insert(i);
                while(val%i==0)
                {
                    val=val/i;
                }
                i++;
            }
            // 剩下的数字不等于一，则就是最后的质数
            if(val!=1)
                primerFactor.insert(val);
        }
        return primerFactor.size();
    }
};
// #3
class Solution {
public:
    int minimumPartition(string s, int k) {
        int i=0;
        long long val=0;
        int count=1;
        while(i<s.size())
        {
            val=(s[i]-'0')+val*10;
            if(s[i]-'0'>k)
                return -1;
            if(val>k)
            {
                val=s[i]-'0';
                count++;
            }
            i++;
        }
        return count;
    }
};

// #4
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        if(right<=2)
            return {-1,-1}; 
        vector<bool> primers(right+1,true);
        primers[0]=false;
        primers[1]=false;
        int i=2;
        vector<int> primersVec;
        while(i<=right)
        {
            if(primers[i])
            {
                if(i>=left)
                    primersVec.push_back(i);
                int j=2*i;
                while(j<=right)
                {
                    primers[j]=false;
                    j+=i;
                }
            }
            i++;
        }
        if(primersVec.size()<=1)
            return {-1,-1};
        int minDiff=INT_MAX;
        int a=-1,b=-1;
        for(int i=0;i<primersVec.size()-1;++i)
        {
            // cout<<primersVec[i]<<" "<<primersVec[i+1]<<endl;
            if(primersVec[i+1]-primersVec[i]<minDiff)
            {
                a=primersVec[i];
                b=primersVec[i+1];
                minDiff=primersVec[i+1]-primersVec[i];
            }
        }
        return {a,b};
    }
};