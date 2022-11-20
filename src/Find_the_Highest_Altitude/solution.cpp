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