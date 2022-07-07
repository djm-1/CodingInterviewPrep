class Solution {
public:
    
    bool comp(string &s1, string &s2){
        int dif=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i])
                dif++;
        }
        return dif==1;
    }
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
         
        set<string>s;
        for(auto x:wordList)
            s.insert(x);
        s.insert(beginWord);
        if(s.find(endWord)==s.end())
            return 0;
        
        queue<string>Q;
        Q.push(beginWord);
        int lvl=0;
        
        unordered_map<string,bool>visited;
        for(auto x:s)
            visited[x]=false;
        
        while(!Q.empty())
        {
            int sz=Q.size();
            for(int i=0;i<sz;i++){
                string curr=Q.front();
                Q.pop();
                visited[curr]=true;
                if(curr==endWord)
                    return lvl+1;
                vector<string>arr;
                for(auto x:s)
                {
                    if(comp(curr,x)){
                        arr.push_back(x);
                    }
                }
                
                for(auto x:arr)
                {
                    if(!visited[x]){
                        Q.push(x);
                        s.erase(x);
                    }
                }
            }
            lvl++;
        }
        return 0;
    }
};