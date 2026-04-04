#include<iostream>
#include<vector>
using namespace std;

bool binarySearch(vector<int> &nums, int target, int st, int end)
{
    if(st<=end)
    {
        int mid = (st+end)/2;
        if(nums[mid] == target)
            return true;
        if(nums[mid] < target)
            return binarySearch(nums,target,mid+1,end);
        else
            return binarySearch(nums,target,st,mid-1);
        
    }
    return false;
}
int main()
{
    vector<int> nums = {1,2,3,4,5,6,7};
    int target =   1;

    if(binarySearch(nums,target,0,nums.size()-1))
        cout<<"Target is present"<<endl;
        else 
        cout<<"Target is not present"<<endl;
    return 0;
}