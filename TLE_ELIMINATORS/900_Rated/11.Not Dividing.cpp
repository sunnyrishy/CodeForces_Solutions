Problem : https://codeforces.com/problemset/problem/1794/B

B. Not Dividing
time limit per test2 seconds
memory limit per test256 megabytes
You are given an array of n positive integers a1,a2,…,an. In one operation, you can choose any number of the array and add 1 to it.

Make at most 2n operations so that the array satisfies the following property: ai+1 is not divisible by ai, for each i=1,2,…,n−1.

You do not need to minimize the number of operations.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). The description of the test cases follows.

The first line of each test case contains an integer n (1≤n≤104) — the length of the given array.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109) — the given array.

It is guaranteed that the sum of n over all test cases does not exceed 5⋅104.

Output
For each test case, print the answer on a separate line.

In the only line, print n integers — the resulting array a after applying at most 2n operations.

We can show that an answer always exists under the given constraints. If there are multiple answers, print any of them.

Example
inputCopy
3
4
2 4 3 6
3
1 2 3
2
4 2
outputCopy
4 5 6 7
3 2 3
4 2
Note
In the first test case, the array [4,5,6,7] can be achieved by applying 2 operations to the first element, 1 operation to the second element, 3 operations to the third element, and 1 operation to the last element. The total number of operations performed is 7, which is less than the allowed 8 operations in this case.

In the second test case, the array [3,2,3] can be achieved by applying two operations to the first element. Another possible resulting array could be [2,3,5], because the total number of operations does not need to be minimum.

In the third test case, not applying any operations results in an array that satisfies the statement's property. Observe that it is not mandatory to make operations.





----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


This problem is a general division based problem.

This is asking to make at most 2*n operations (operation - take any element from array a and add 1 to it). By doing this we need to create such an array that Ai+1 it not divisible by Ai.
for any Ai+1 to not be divisible by Ai,
One possibility could be Ai = 1 which divides every Ai+1.
One other possibility could be Ai = a divisor of Ai+1.

We will sove the first possibility by iterating the array and find all the occurances of Ai = '1' and make it to 2 (Ai++)
Since we make it 2, now Ai could be 2 or a divisor of Ai+1, to tackle this we will simply increase the Ai+1 value by 1(Ai+1 ++).

This will make sure the Ai will not be a divisor of Ai+1.


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
        
        for(long long i = 0; i < n; i++){
            if(arr[i] == 1){.   // all the occurances of 1 will now turn to 2
                arr[i]++;
            }
        }
        
        for(int i = 1; i <= n-1; i++){
            if(arr[i] % arr[i-1] == 0) arr[i]++;    //if a[i[ is divising a[i+1] we will increase the a[i+1] by 1
        }
        for(long long i = 0; i < n; i++){
            cout<<arr[i]<<" ";  //printing the modified array
        }
        cout<<endl;
    }
    return 0;
}
