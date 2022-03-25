class Solution {
public:
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        vector<int>temp=arr;
        
        sort(arr.begin(),arr.end(),[x](int &a, int &b){
            if(abs(a-x)<abs(b-x))
                return true;
            else if(abs(a-x)==abs(b-x) && a<b)
                return true;
            else
                return false;
        });
        
        vector<int>elem;
        for(int i=0;i<k;i++)
        {
            elem.push_back(arr[i]);
        }
        sort(elem.begin(),elem.end());
        return  elem;
        
    }
};