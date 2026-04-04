#include<iostream>
#include<vector>
using namespace std;

void getAllSubset(vector<int> &arr, vector<int> &ans, int i , vector<vector<int>> &allSubset )
{
    if(i == arr.size())
        {
            allSubset.push_back({ans});
        
            return;
        }
    //include
    ans.push_back(arr[i]);
    getAllSubset(arr,ans,i+1,allSubset);
    //backtrack
    ans.pop_back();
    //exclude
    getAllSubset(arr,ans,i+1,allSubset);
}
int main()
{
    vector<int> arr = {1,2,3};
    vector<int> ans;
    vector<vector<int>> allSubset;
    getAllSubset(arr,ans,0,allSubset);
      for(auto subset : allSubset)
    {
        cout << "{ ";
        for(int x : subset)
            cout << x << " ";
        cout << "}" << endl;
    }
    return 0;
}