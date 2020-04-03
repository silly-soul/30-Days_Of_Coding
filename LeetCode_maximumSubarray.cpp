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

class  Solution
{
public:
    //O(n)--doesn't work with negative numbers only.
    int maxSubArray(vector<int>& nums)
    {
        int cs=0,ms=0;

        for(int i=0; i<nums.size(); i++)
        {

            cs+=nums[i];
            if(cs<0)
            {
                cs=0;
            }
            ms=max(cs,ms);
        }
        return ms;
    }

    //O(n^2) 12ms --PreComputing
    int maxSubArray(vector<int>& nums)
    {
        int maxSum=INT_MIN;
        int curr_sum=0;
        vector<int> V;
        V.push_back(nums[0]);
        for(int i=1; i<nums.size(); i++)
        {
            V.push_back(V[i-1]+nums[i]);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i; j < nums.size(); j++)
            {
                curr_sum=V[j]-V[i-1];
            }

            if(maxSum<curr_sum)
            {
                maxSum=curr_sum;

            }


        }
        cout<< maxSum;
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
