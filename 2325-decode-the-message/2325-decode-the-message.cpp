class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        char start='a';
        for(auto x:key)
        {
            if(x==' ')
                continue;
            if(!mp[x])
            {   mp[x]=start;
                start++;
            } 
        }
        
        for(int i=0;i<message.size();i++)
        {
            if(message[i]!=' '){
                message[i]=mp[message[i]];
            }
        }
        
        return message;
    }
};