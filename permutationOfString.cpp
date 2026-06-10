#include<iostream>
#include<vector>
using namespace std;

void getPerms(string &str,int idx, vector<string> &ans)
{
    if(idx == str.length())
    {
        ans.push_back(str);
        return;
    }
    for(int i = idx; i<str.length();i++)
    {
        swap(str[i],str[idx]);
        getPerms(str,idx+1,ans);
         swap(str[i],str[idx]);
    }
}
int main()

{
    string str = "ABC";
    vector<string> ans;
    getPerms(str,0,ans);
    for(auto &s : ans)
        cout<<s<<endl;
    return 0;

}