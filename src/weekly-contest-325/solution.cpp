// #1
class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        int result = words.size();
        int n = words.size();
        for (int i = 0; i < words.size(); ++i)
        {
            if (words[i] == target)
            {
                int distance = min(abs(startIndex - i), n - abs(startIndex - i));
                result = min(result, distance);
            }
        }
        if (result == n)
        {
            return -1;
        }
        else
        {
            return result;
        }
    }
};

// #2
class Solution
{
public:
    int takeCharacters(string s, int k)
    {
        vector<int> counts(3, 0);
        int j = s.size();
        int n = s.size();
        while (counts[0] < k || counts[1] < k || counts[2] < k)
        {
            if (j == 0)
            {
                return -1;
            }
            j -= 1;
            counts[s[j] - 'a']++;
        }
        int result = n - j;
        for (int i = 0; i < n; ++i)
        {
            counts[s[i] - 'a']++;
            while (j < n && counts[s[j] - 'a'] > k)
            {
                counts[s[j] - 'a'] -= 1;
                j += 1;
            }
            result = min(result, i + 1 + n - j);
        }
        return result;
    }
};

// #3
class Solution
{
public:
    int maximumTastiness(vector<int> &price, int k)
    {
        sort(price.begin(), price.end());
        int n=price.size();
        int left=0,right=price[n-1]-price[0]+1;
        while(left<right)
        {
            int mid=left+(right-left)/2;
            bool result=checkX(price,mid,k);
            if(result)
            {
                left=mid+1;
            }
            else
            {
                right=mid;
            }
        }
        return left-1;
    }
    bool checkX(const vector<int> &price, int x, int k)
    {
        int count = 1;
        int pre=price[0];
        int i=0;
        while(i<price.size())
        {
            if(price[i]-pre>=x)
            {
                count++;
                pre=price[i];
            }
            i++;
        }
        return  count>=k;
    }
};