// 第一题数据数量少，直接暴露
class Solution {
public:
   vector<int> distinctDifferenceArray(vector<int> &nums) {
       // todo 使用map
       vector<int> result(nums.size(),0);
       for(int i=0;i<nums.size();++i){
           set<int> pre,last;
           for(int j=0;j<=i;++j){
               pre.insert(nums[j]);
           }
           for(int j=i+1;j<nums.size();++j){
               last.insert(nums[j]);
           }
           result[i]=pre.size()-last.size();
       }
       return result;
   }
};

// 第二题 采用两个map,一个map保存某个数字出现的次数，另一个map保存特定频率的数字个数
class FrequencyTracker {
public:
   FrequencyTracker() {

   }

   void add(int number) {

       if (counts.count(stores[number]) > 0) {
           counts[stores[number]]--;
           if (counts[stores[number]] == 0) {
               counts.erase(stores[number]);
           }
       }
       stores[number]++;
       counts[stores[number]]++;

   }

   void deleteOne(int number) {
       if (stores.count(number) > 0) {
           counts[stores[number]]--;
           counts[stores[number]-1]++;
           if (counts[stores[number]] == 0) {
               counts.erase(stores[number]);
           }
           stores[number]--;
           if (stores[number] == 0) {
               stores.erase(number);
           }
       }
   }

   bool hasFrequency(int frequency) {
       if (counts.count(frequency) > 0) {
           return true;
       } else {
           return false;
       }
   }

private:
   map<int, int> stores;
   map<int, int> counts;

};

// 第三题 每次填充颜色只会影响index两边相邻的结果，因此只需要判断某次填充前后index处的相邻颜色影响次数
class Solution {
public:
   vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
       vector<int> array(n,0);
       vector<int> answer(queries.size(),0);
       for(int i=0;i<queries.size();++i){
           int index=queries[i][0];
           int color=queries[i][1];

           int preCount=0;
           int curCount=0;
           if(index>0 && array[index]!=0 &&array[index]==array[index-1]){
               preCount++;
           }
           if(index<n-1 && array[index]!=0 && array[index]==array[index+1]){
               preCount++;
           }

           if(index>0 && color==array[index-1]){
               curCount++;
           }

           if(index<n-1 && color==array[index+1]){
               curCount++;
           }
           array[index]=color;

           if(i>0){
               answer[i]=answer[i-1]-preCount+curCount;
           }
       }
       return answer;
   }
};

// 第四题，要想根节点到叶子节点的路径值都相等，首先要确保叶子节点上的两个兄弟节点的路径值相等，由于只能+1操作，因此只需要确保两个兄弟节点的路径值成为最大的那个即可。
// 然后不断地向上递归，将夫节点的路径值更新为夫节点的路径值加一个兄弟节点的路径值。然后夫节点和对应兄弟节点继续迭代。
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        vector<int> result(cost);
        int count=0;
        int i=n/2;
        while(i>0){
            for(int j=i;j<i*2;j+=2){
                count+=max(result[j],result[j+1])-min(result[j], result[j+1]);
                result[j/2]+=max(result[j],result[j+1]);
            }
            i=i/2;
        }
        return count;
    }
};
