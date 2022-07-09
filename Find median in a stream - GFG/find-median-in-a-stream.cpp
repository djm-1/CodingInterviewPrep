// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution
{
    public:
    //Function to insert heap.
    
    priority_queue<int>left;
    priority_queue<int, vector<int>,greater<int>>right;
    
    // right will be min heap
    // left will be max heap
    
    void insertHeap(int &x)
    {
        if(left.size()==0)
        {
            left.push(x);
            return;
        }
            
        if(left.size()>right.size())
        {
            if(x<left.top())
            {
                int m=left.top();
                left.pop();
                left.push(x);
                right.push(m);
            }
            else
            {
                right.push(x);
            }
        }
        else
        {
            if(x<left.top())
            {
                left.push(x);
            }
            else
            {
                /* get the excess element from right
                x>left.top() is fine but no gurantee that x<right.top()
                so push into ribht first then transfer the excess element */ 
                
                right.push(x);
                int m=right.top();
                right.pop();
                left.push(m);
            }
        }
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(left.size()==right.size())
            return (double)(left.top()+right.top())/2;
            
        return (double)left.top();
    }
};


// { Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin>>t;
    while(t--)
    {
    	Solution ob;
    	cin >> n;
    	for(int i = 1;i<= n; ++i)
    	{
    		cin >> x;
    		ob.insertHeap(x);
    	    cout << floor(ob.getMedian()) << endl;
    	}
    }
	return 0;
}  // } Driver Code Ends