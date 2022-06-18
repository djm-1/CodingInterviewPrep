class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long int n=arr.size();
        vector<long long int>NSR(n,n);
        vector<long long int>NSL(n,-1);
        
        stack<long long int>st;
        for(long long int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && arr[st.top()]>arr[i])
                {
                    long long int x=st.top();
                    NSR[x]=i;
                    st.pop();
                }
                if(!st.empty())
                {
                    NSL[i]=st.top();
                }
                
                st.push(i);
            }
        }
        
        long long int mod=1e9+7,sum=0;
        
        for(long long int i=0;i<n;i++)
        {
            sum=(sum+arr[i]*((NSR[i]-i)*(i-NSL[i]))%mod)%mod;
        }
        return sum;
    }
};