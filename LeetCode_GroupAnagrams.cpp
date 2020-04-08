/*
 * Author : Aditya Agrawal
 * Date   : April-2020
 *
 * Compiler : g++ 8.2.0
 * flags    : -std=c++11
 */


 /*****
Given an array of strings, group anagrams together.
Example:
Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

 **/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //O(N)
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string> > mp;
	vector<vector<string> > final_set;

	for (int i = 0; i < strs.size(); i++)
	{
        string key = strs[i];
		sort(key.begin(), key.end());
		mp[key].push_back(strs[i]);

	}

	for (auto i : mp)
	{
		final_set.push_back(i.second);
	}
	return final_set;
    }
};
//driver code
int main(){
vector<string> strs;
    strs.push_back("eat");
    strs.push_back("tea");
    strs.push_back("tan");
    strs.push_back("ate");
    strs.push_back("nat");
    strs.push_back("bat");

    Solution sol;
    sol.groupAnagrams(strs);
}
