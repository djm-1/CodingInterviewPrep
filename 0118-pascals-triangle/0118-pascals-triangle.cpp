class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>arr;
        vector<int>def_arr;
        def_arr.push_back(1);
        for(int i=0;i<numRows;i++){
            if(i==0){
                arr.push_back(def_arr);
            }
            else{
                int sze=i+1;
                vector<int>dummy(sze,1);

                for(int j=1;j<=i-1;j++){
                    dummy[j]=arr[i-1][j-1]+arr[i-1][j];
                }

                arr.push_back(dummy);
            }

        }

        return arr; 
    }
};