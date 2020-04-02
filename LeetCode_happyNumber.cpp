/*
 * Author : Aditya Agrawal
 * Date   : April-2020
 *
 * Compiler : g++ 8.2.0
 * flags    : -std=c++11
 */


/**
A happy number is a number defined by the following process: Starting with any positive integer,replace the number by the sum of
the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy numbers.

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
**/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int digitSquare(int n)
    {
        int sq = 0;
        while (n)
        {
            sq += (n%10) * (n%10);
            n = n / 10;
        }
        return sq;
    }

//4ms -- LoopHole -- the given nos. form a cycle upto n=1000
    bool isHappy(int n)
    {
        unordered_set<int> s{4, 16, 37, 58, 89, 145, 42, 20 };
        while(n)
        {
            if(n==1)
            {
                return 1;
                break;
            }
            else if(s.find(n) != s.end())
            {
                return 0;
                break;
            }
            else
            {
                n=digitSquare(n);
            }
        }

        return -1;
    }

    //0ms -- Loophole
    bool isHappy(int n)
    {
        vector<int> s{4, 16, 37, 58, 89, 145, 42, 20 };
        while(1)
        {
            if(n==1)
            {
                return 1;
                break;
            }


            auto it=find(s.begin(),s.end(),n);
            if(it!=s.end())
            {
                return 0;
                break;
            }

            else
            {
                n=digitSquare(n);
            }
        }



    }

//0ms -- BestCase
    bool isHappy(int n)
    {
        vector<int> s;
        while(1)
        {
            if(n==1)
                return 1;
            auto itr=find(s.begin(),s.end(),n);
            if(itr!=s.end())
                return 0;
            s.push_back(n);
            n=digitSquare(n);

        }
    }

};
// Driver code
int main()
{
    int n;
    cin >> n;
    Solution sol;
    bool res = sol.isHappy(n);

    cout << res <<endl;


}
