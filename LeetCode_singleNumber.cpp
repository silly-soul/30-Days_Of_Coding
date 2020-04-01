/*
 * Author : Aditya Agrawal
 * Date   : April-2020
 *
 * Compiler : g++ 8.2.0
 * flags    : -std=c++11
 */

/*Given a non-empty array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

*/

#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    //21-30ms
    void singleNumber(vector<int>& nums)
    {/*
        // Insert all array elements in hash
        // table
        unordered_map<int, int> ht;
        for (auto i : nums)
            ht[i]++;

        // Traverse through map only and
        for (auto itr : ht)
            if (itr.second == 1)
                cout << itr.first << " ";

    } */
    //12ms
    void singleNumberXor(vector<int>& nums)
    {
        // same number xor will be 0
        int result = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            result ^= nums[i];
        }
        cout<< result << endl;
    }
   /*
    //18-20ms
    int singleNumberOther(vector<int>& nums)
    {
        unordered_map<int,int> t;
        for(auto num : nums)
            t[num]++;
        for(auto itr = t.begin(); itr != t.end(); itr++)
        {
            if(itr->second == 1)
                cout << itr->first<< endl;
        }
        return 0;
    } */
};


//driver function
int main()
{
    int input;
    vector<int> nums;
    while (cin >> input && input != 9999)
    {
        nums.push_back(input);
    }
    Solution sol;
    // sol.singleNumber(nums);
    sol.singleNumberXor(nums);
    //sol.singleNumberOther(nums);
    return 0;
}

