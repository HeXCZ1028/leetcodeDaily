#include<vector>
using namespace std;

// 1
class Solution {
    vector<int> evenOddBit(int n) {
        vector<int> array;
        int i=0;
        while (n != 0) {
            array[i]+=n&1;
            n>>=1;
            i^=1;
        }
        return array;
    }
};

// 2
class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        int n=grid.size();

        int i=0;
        int x=0,y=0;
        while(i<n*n){
            if(grid[x][y]!=i)
                return false;
            vector<int> next=nextLocation(i+1,x,y,n,grid);
            if(i+1==n*n){
                return true;
            }
            if(next[0]==-1){
                //cout<<"fsl"<<i+1<<endl;
                return false;
            }
            x=next[0];
            y=next[1];
            i++;
        }
        return true;
    }
    vector<int> nextLocation(int index,int x,int y,const int n,const vector<vector<int>> &grid){
        for(int i=x-2;i<=x+2;++i){
            for(int j=y-2;j<=y+2;++j){
                if(i==x || j==y)
                    continue;
                if(i>=0 && i<n && j>=0 &&j<n){
                    // cout<<i<<" "<<j<<endl;
                    if(abs(i-x)+abs(j-y)==3 && grid[i][j]==index){
                        // cout<<i<<" "<<j<<" "<<index<<endl;
                        return {i,j};
                    }
                }
            }
        }
        return {-1,-1};
    }
};
