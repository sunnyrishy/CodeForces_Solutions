Problem : https://codeforces.com/problemset/problem/1582/B


B. Luntik and Subsequences
time limit per test1 second
memory limit per test256 megabytes
Luntik came out for a morning stroll and found an array a of length n. He calculated the sum s of the elements of the array (s=∑ni=1ai). Luntik calls a subsequence of the array a nearly full if the sum of the numbers in that subsequence is equal to s−1.

Luntik really wants to know the number of nearly full subsequences of the array a. But he needs to come home so he asks you to solve that problem!

A sequence x is a subsequence of a sequence y if x can be obtained from y by deletion of several (possibly, zero or all) elements.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases. The next 2⋅t lines contain descriptions of test cases. The description of each test case consists of two lines.

The first line of each test case contains a single integer n (1≤n≤60) — the length of the array.

The second line contains n integers a1,a2,…,an (0≤ai≤109) — the elements of the array a.

Output
For each test case print the number of nearly full subsequences of the array.

Example
inputCopy
5
5
1 2 3 4 5
2
1000 1000
2
1 0
5
3 0 2 1 1
5
2 1 0 3 0
outputCopy
1
0
2
4
4
Note
In the first test case, s=1+2+3+4+5=15, only (2,3,4,5) is a nearly full subsequence among all subsequences, the sum in it is equal to 2+3+4+5=14=15−1.

In the second test case, there are no nearly full subsequences.

In the third test case, s=1+0=1, the nearly full subsequences are (0) and () (the sum of an empty subsequence is 0).






----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Intuition : We are looking for all subarrays with sum = total_sum - 1;
To get all possible subarrays with sum = total_sum - 1 we need to drop any 1 from the element .

  We can drop 0 or we can not drop it because 0 will not effect the summation.

  We will iterate through the array and have a count of 0 and 1 and then if there are no 1 then we cant have any subarray with sum = total sum - 1
  if there exists 1 >= (1) then we will have some subarray and then 2 choices for each zero existance either to drop it or to keep it.


  Code : 


#include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long> arr(n);
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        long long c0 = 0;    //count 0
        long long c1 = 0;    //count 1
        for(int i = 0; i < n; i++){
            if(arr[i] == 0) c0++;
            else if (arr[i] == 1) c1++;
        }
        
        if(c1 == 0) cout<<0<<endl;   //if no ones exist
        else{
            cout<<c1 * (1LL << c0)<<endl;  //number of ones times two options for each zero drop or keep
                       //bit shifting
        }
    }
    return 0;
}
