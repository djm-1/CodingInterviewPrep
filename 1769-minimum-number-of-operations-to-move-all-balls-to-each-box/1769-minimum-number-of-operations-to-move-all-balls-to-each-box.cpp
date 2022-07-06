class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n=boxes.size();
        vector<int>ltr(n);
        vector<int>rtl(n);
        
        ltr[0]=boxes[0]-'0';
        for(int i=1;i<n;i++)
        {
            ltr[i]=ltr[i-1]+(boxes[i]-'0');
        }
        
        rtl[n-1]=boxes[n-1]-'0';
        for(int i=n-2;i>=0;i--)
        {
            rtl[i]=rtl[i+1]+(boxes[i]-'0');
        }
        
        for(int i=1;i<n;i++)
        {
            ltr[i]+=ltr[i-1];
        }
        
        for(int i=n-2;i>=0;i--)
        {
            rtl[i]+=rtl[i+1];
        }
        
        vector<int>ans(n);
        
        for(int i=0;i<n;i++)
        {
            ans[i]=(i-1>=0?ltr[i-1]:0)+(i+1<n?rtl[i+1]:0);
        }
        return ans;
    }
};