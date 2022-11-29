class Solution {
public:
    int minOperations(string s) {
        int aResult=0,bResult=0;
        char a='0';
        int flag=0;
        for(int i=0;i<s.size();++i){
            char c=a+flag;
            if(s[i]!=c)
                aResult++;
            flag=1-flag;
            c=a+flag;
            if(s[i]!=c)
                bResult++;
        }
        return min(aResult,bResult);
    }
};