#include<iostream>
#include<vector>
using namespace std;

void getPerms(vector<int> &nums, int idx, vector<vector<int>> &ans)
{
    if(idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i = idx;i< nums.size();i++)
    {
        swap(nums[idx],nums[i]);
        getPerms(nums,idx+1,ans);
        swap(nums[idx],nums[i]);
    }

}
int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans;
    getPerms(nums,0,ans);
     for (auto num : ans)
    {
        for (auto x : num)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}