/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int,int>mp;
    
    int dfs(vector<Employee*> employees, int id){
        if((employees[id]->subordinates).size()==0)
            return employees[id]->importance;
        
        int ans=employees[id]->importance;
        for(auto x:employees[id]->subordinates)
        {
            ans+=getImportance(employees,x);
        }
        return ans;
    }
    
    
    int getImportance(vector<Employee*> employees, int id) {
        
        
        for(int i=0;i<employees.size();i++)
            mp[employees[i]->id]=i;
       
        return dfs(employees,mp[id]);
    }
};