/*
 * Author : Aditya Agrawal
 * Date   : April-2020
 *
 * Compiler : g++ 8.2.0
 * flags    : -std=c++11
 */

/**
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

**/






#include<bits/stdc++.h>
using namespace std;


class Solution
{
//0ms--O(n)--Single Transaction at a time:
public:
    int maxProfit(vector<int>& prices)
    {
        if(prices.empty())
        {
            return 0;
        }
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
            if (prices[i] > prices[i - 1])
                profit += (prices[i] - prices[i - 1]);
        return profit;
    }
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
    int result=sol.maxProfit(nums);
    cout << result <<endl;


}

