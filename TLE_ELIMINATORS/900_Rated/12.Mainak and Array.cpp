Problem : https://codeforces.com/problemset/problem/1726/A

A. Mainak and Array
time limit per test1 second
memory limit per test256 megabytes
Mainak has an array a1,a2,…,an of n positive integers. He will do the following operation to this array exactly once:

Pick a subsegment of this array and cyclically rotate it by any amount.
Formally, he can do the following exactly once:
Pick two integers l and r, such that 1≤l≤r≤n, and any positive integer k.
Repeat this k times: set al=al+1,al+1=al+2,…,ar−1=ar,ar=al (all changes happen at the same time).
Mainak wants to maximize the value of (an−a1) after exactly one such operation. Determine the maximum value of (an−a1) that he can obtain.

Input
Each test contains multiple test cases. The first line contains a single integer t (1≤t≤50) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤2000).

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤999).

It is guaranteed that the sum of n over all test cases does not exceed 2000.

Output
For each test case, output a single integer — the maximum value of (an−a1) that Mainak can obtain by doing the operation exactly once.

Example
inputCopy
5
6
1 3 9 11 5 7
1
20
3
9 99 999
4
2 1 8 1
3
2 1 5
outputCopy
10
0
990
7
4
Note
In the first test case, we can rotate the subarray from index 3 to index 6 by an amount of 2 (i.e. choose l=3, r=6 and k=2) to get the optimal array:
[1,3,9,11,5,7–––––––––]⟶[1,3,5,7,9,11–––––––––]
So the answer is an−a1=11−1=10.
In the second testcase, it is optimal to rotate the subarray starting and ending at index 1 and rotating it by an amount of 2.
In the fourth testcase, it is optimal to rotate the subarray starting from index 1 to index 4 and rotating it by an amount of 3. So the answer is 8−1=7.




---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


In this we are asked to find the max value that we can obtain (an-a1) by any kind of ratating the array.

to maximize the difference of an-ai we either need to change value in an position or at a1 position or both the position.

Type1 : Fixing an.
  If we consider locking the an position (1 based indexing), we can have all the possible options from a1 to an-1 at a1 positon. 
  Then we can find the max value of an-a1.

  Type1 : Fixing a1
  If we consider locking the a1 position, we can have all the possbile options from a2 to an at an position.
  Then we can find the max value of an-a1.

  Type 3 : If we choose to rotate the complete entire array, then on rotation we end up find the difference between ai and ai+1.



  
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
        for(long long i = 0; i < n; i++) cin>>arr[i];
        
        long long ans = arr[n-1]-arr[0];   //initially answer be an-a1
        
        //fixing n-1 element
        for(long long i = 0; i < n-1; i++){
            ans = max(ans, arr[n-1] - arr[i]);    //fixing last element
        }
        //fixing 0th index
        for(long long i = 1; i <= n-1; i++){
            ans = max(ans, arr[i] - arr[0]);     //fixing first element
        }
        for(long long i = 0; i < n-1; i++){
            ans = max(ans, arr[i] - arr[i+1]);    //selecting the complete array to rotote, an and a1 both will get changed
        }
        cout<<ans<<endl;
    }
    return 0;
}
