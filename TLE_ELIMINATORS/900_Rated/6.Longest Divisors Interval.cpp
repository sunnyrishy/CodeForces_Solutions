Problem : https://codeforces.com/problemset/problem/1855/B

B. Longest Divisors Interval
time limit per test2 seconds
memory limit per test256 megabytes 
Given a positive integer n, find the maximum size of an interval [l,r] of positive integers such that, for every i in the interval (i.e., l≤i≤r), n is a multiple of i.

Given two integers l≤r, the size of the interval [l,r] is r−l+1 (i.e., it coincides with the number of integers belonging to the interval).

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases.

The only line of the description of each test case contains one integer n (1≤n≤1018).

Output
For each test case, print a single integer: the maximum size of a valid interval.

Example
inputCopy
10
1
40
990990
4204474560
169958913706572972
365988220345828080
387701719537826430
620196883578129853
864802341280805662
1000000000000000000
outputCopy
1
2
3
6
4
22
3
1
2
2
Note
In the first test case, a valid interval with maximum size is [1,1] (it's valid because n=1 is a multiple of 1) and its size is 1.

In the second test case, a valid interval with maximum size is [4,5] (it's valid because n=40 is a multiple of 4 and 5) and its size is 2.

In the third test case, a valid interval with maximum size is [9,11].

In the fourth test case, a valid interval with maximum size is [8,13].

In the seventh test case, a valid interval with maximum size is [327869,327871].

-----------------------------------------------------------------------------------------------------------------------------------------------

  Intuition : We are supposed to find the interval [l,r] that has all the divisors of n.


  If there exisits some range [l,r] then there existis a range form 1 to l-r+1 that has all the divisors of [l,r] and can divide n.



  Code : 



  #include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long i = 1;
        while(n%i == 0){
            i++;
        }
        cout<<i-1<<endl;
    }
    return 0;
}
  
