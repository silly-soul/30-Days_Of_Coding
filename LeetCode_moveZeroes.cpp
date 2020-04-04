/*
 * Author : Aditya Agrawal
 * Date   : April-2020
 *
 * Compiler : g++ 8.2.0
 * flags    : -std=c++11
 */

/*Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]*/



#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //0 ms - O(n)in place without making a copy of the array.
    //Single Traversal -- With Swap()
    void moveZeroes(vector<int>& nums)
    {
        int temp=0;
        for (int i=0; i<nums.size(); i++)
            if (nums[i] != 0)
                swap(nums[temp++], nums[i]);

    }


    void moveZeroes(vector<int>& nums)
    {
        int count = 0;
        // If the current element is not 0, then we need to
        // append it just in front of last non 0 element we found.
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[count++] = nums[i];
            }
        }
        // all the non-zero elements are already at beginning of array.
        // filling the remaining array with 0's.
        for (int i = count; i < nums.size(); i++)
        {
            nums[i] = 0;
        }
    }



};
//driver code:
int main()
{
    vector<int> nums;
    int input;
    while(cin>>input)
    {
        nums.push_back(input);
    }

    Solution sol;
    sol.moveZeroes(nums);
    for(int i=0; i<nums.size(); i++)
    {
        cout<<nums[i]<<endl;
    }

}
