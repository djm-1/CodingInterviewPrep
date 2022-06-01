class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        int count=0;
        int n=stockPrices.size();
        sort(stockPrices.begin(),stockPrices.end());
        if(n==1||n==0)
            return 0;
        else if(n==2)
            return 1;
        else
        {
            
            for(int i=2;i<n;i++)
            {
                long long x1=stockPrices[i][0], x2=stockPrices[i-1][0], x3=stockPrices[i-2][0];
                long long y1=stockPrices[i][1], y2=stockPrices[i-1][1], y3=stockPrices[i-2][1];
                
                long long comp1=(y2-y1)*(x3-x2);
                long long comp2=(y3-y2)*(x2-x1);
                
                if(comp1!=comp2)
                    count++;
            }
        }
        
        return count+1;
    }
};