/*
 * Author : Aditya Agrawal
 * Date   : April-2020
 *
 * Compiler : g++ 8.2.0
 * flags    : -std=c++11
 */


 /****
Given an integer array arr, count element x such that x + 1 is also in arr.

If there're duplicates in arr, count them seperately.
Example 1:
Input: arr = [1,2,3]
Output: 2
Explanation: 1 and 2 are counted cause 2 and 3 are in arr.
 **/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 0ms -- O(N)
    int countElements(vector<int>& arr) {
        int count=0;
       set<int> s;

        for(int i : arr){
            s.insert(i);
        }


        for(int j: arr){
            if(s.find(j+1)!=s.end()){
                count++;
            }
        }
        return count;
    }
};

//driver code
int main(){
vector<int> arr;
int input;
while(cin>>input){
    arr.push_back(input);
}

Solution sol;
int res = sol.countElements(arr);
cout << res;


}
