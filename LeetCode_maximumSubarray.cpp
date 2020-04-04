/*
 * Author : Aditya Agrawal
 * Date   : April-2020
 *
 * Compiler : g++ 8.2.0
 * flags    : -std=c++11
 */

/*Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/

#include<bits/stdc++.h>
using namespace std;

class  Solution
{
public:
    //O(n) Time and O(1)-Space--Kadane's Algo. -4ms
      int maxSubArray(vector<int>& nums)
      {
          int cs=0,ms=0;

          for(auto i:nums)
          {

              cs+=nums[i];
              ms=max(cs,ms);
              if(cs<0)
              {
                  cs=0;
              }

          }
          return ms;
      }

     //O(n)--Time and Space-- 4ms --PreComputing--cumulative Sum
    int maxSubArray(vector<int>& nums)
    {
        int n=nums.size();
        int maxSum=INT_MIN;
        int curr_sum=0;
        vector<int> V(n);
        for(int i=0; i<n; ++i)
        {
            V[i]=nums[i]+ (i==0 ? 0 : V[i-1]);
        }
        for (int j = 0; j < n; j++)
        {
            maxSum=max(maxSum,V[j]-curr_sum);
            curr_sum=min(curr_sum,V[j]);
        }
        cout<< maxSum;
    }

    //O(n^2) 12ms --BruteForce
    int maxSubArray(vector<int>& nums)
    {
        int maxSum=INT_MIN;
        for (int i=0; i<nums.size();i++)
        {
            int curr_sum=0;
            for (int j = i; j < nums.size(); j++)
            {
                curr_sum+=nums[j];
                if (curr_sum > maxSum)
                    maxSum = curr_sum;
            }

        }
        cout << maxSum;
    }

    /*
    //Brute-Force-- O(n^3)---TLE
        int maxSubArray(vector<int>& nums)
        {

            int maxSum=INT_MIN;
            auto left=nums.begin(),right=nums.end();
            int curr_sum=0;
            for (auto i = nums.begin(); i != nums.end(); ++i)
            {
                for (auto j = i; j != nums.end(); ++j)
                {
                    curr_sum=0;
                    for(auto k=i; k<=j; k++)
                    {
                        cout<<*k << " ";
                        curr_sum+=*k;
                    }
                    cout<< "=>"<<curr_sum;
                     cout<<endl;
                    if(maxSum<curr_sum){
                        maxSum=curr_sum;
                        left=i;
                        right=j;
                    }

                }
            }

            for(auto i = left; i <=right; i++){
                cout<<*i<< " ";
            }
            cout<<maxSum;

        }
    */

};


int main()
{
    vector<int> nums;
    int input;
    while(cin>>input)
    {
        nums.push_back(input);
    }

    Solution sol;
    sol.maxSubArray(nums);



}
