#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void getAllSubset(vector<int> &arr, vector<int> &ans, int i, vector<vector<int>> &allSubset)
{
    if(i == arr.size())
    {
        allSubset.push_back(ans);  // ✅ fixed
        return;
    }

    // include
    ans.push_back(arr[i]);
    getAllSubset(arr, ans, i + 1, allSubset);

    // backtrack
    ans.pop_back();

    // skip duplicates
    int idx = i + 1;
    while(idx < arr.size() && arr[idx] == arr[i])
        idx++;

    // exclude
    getAllSubset(arr, ans, idx, allSubset);  
}

int main()
{
    vector<int> arr = {1,2,2};

    sort(arr.begin(), arr.end());  

    vector<int> ans;
    vector<vector<int>> allSubset;

    getAllSubset(arr, ans, 0, allSubset);

    for(auto subset : allSubset)
    {
        cout << "{ ";
        for(int x : subset)
            cout << x << " ";
        cout << "}" << endl;
    }

    return 0;
}