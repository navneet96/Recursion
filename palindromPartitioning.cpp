#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Check if a string is palindrome
    bool isPalin(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        return s == s2;
    }

    // Backtracking function
    void getAllParts(string s,
                     vector<string> &partition,
                     vector<vector<string>> &ans) {

        // Base case
        if (s.size() == 0) {
            ans.push_back(partition);
            return;
        }

        // Try every possible prefix
        for (int i = 0; i < s.size(); i++) {
            string part = s.substr(0, i + 1);

            if (isPalin(part)) {
                partition.push_back(part);

                // Recur for remaining string
                getAllParts(s.substr(i + 1), partition, ans);

                // Backtrack
                partition.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        getAllParts(s, partition, ans);

        return ans;
    }
};

int main() {
    Solution obj;

    string s;
    cout<<"Enter String : ";
    cin >> s;

    vector<vector<string>> result = obj.partition(s);

    for (auto &vec : result) {
        for (auto &str : vec) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}