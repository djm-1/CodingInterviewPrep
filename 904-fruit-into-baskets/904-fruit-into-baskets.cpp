class Solution {
public:
    
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int>mp;
        
        int start=0;
        int max_len=0;
        for(int end=0;end<n;end++){
            mp[fruits[end]]++;
            if(mp.size()<=2)
            {
                max_len=max(max_len,end-start+1);
            }
            else if(mp.size()>2)
            {
                while(mp.size()>2){
                    if(--mp[fruits[start]]==0)
                        mp.erase(fruits[start]);
                    start++;
                }
            }
        }
        
        return max_len;
    }
};