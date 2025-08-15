Problem : https://codeforces.com/problemset/problem/1696/B


B. NIT Destroys the Universe
time limit per test2 seconds
memory limit per test512 megabytes
For a collection of integers S, define mex(S) as the smallest non-negative integer that does not appear in S.

NIT, the cleaver, decides to destroy the universe. He is not so powerful as Thanos, so he can only destroy the universe by snapping his fingers several times.

The universe can be represented as a 1-indexed array a of length n. When NIT snaps his fingers, he does the following operation on the array:

He selects positive integers l and r such that 1≤l≤r≤n. Let w=mex({al,al+1,…,ar}). Then, for all l≤i≤r, set ai to w.
We say the universe is destroyed if and only if for all 1≤i≤n, ai=0 holds.

Find the minimum number of times NIT needs to snap his fingers to destroy the universe. That is, find the minimum number of operations NIT needs to perform to make all elements in the array equal to 0.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤104). Description of the test cases follows.

The first line of each test case contains one integer n (1≤n≤105).

The second line of each test case contains n integers a1, a2, …, an (0≤ai≤109).

It is guaranteed that the sum of n over all test cases does not exceed 2⋅105.

Output
For each test case, print one integer — the answer to the problem.

Example
inputCopy
4
4
0 0 0 0
5
0 1 2 3 4
7
0 2 3 0 1 2 0
1
1000000000
outputCopy
0
1
2
1
Note
In the first test case, we do 0 operations and all elements in the array are already equal to 0.

In the second test case, one optimal way is doing the operation with l=2, r=5.

In the third test case, one optimal way is doing the operation twice, respectively with l=4, r=4 and l=2, r=6.

In the fourth test case, one optimal way is doing the operation with l=1, r=1.




--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------''

In this problem we were asked to find the min possible times to make the mex(s) to be destroyed.

  Case 1 : If we have all the elements in the array to be '0' we do not need to change anything we can simply print 0
  Casw 2 : If there is only 1 segment that are non-zeros and the rest of elements are zeros, then we can consider that segment and change its mex to 0 and that segment will become 0
           Ultimately the cmoplete array will become 0 and it can be destroyed according to the problem statement.

  Case 3 : If there are multiple segments in the array something like [0,0,1,2,3,0,0,,5,6,0,0,0,4,5,6,7,0,0]
          In this case we can consider the entire array and find its mex and completely trandform the entire array with mex value and 
          and then again reconsider the complere array and make the mex value to 0 and destroy it.





The solution can either be 0 or 1 or 2.


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
        long long zeros = 0;   // count the number of zeros in the given array
        for(long long i = 0; i < n; i++){
            if(arr[i] == 0) zeros++;
        }
        long long left = 0;    //left most number that is not equal to zero
        long long right = n-1;  //right most number ths is not equal to zero
        while (left < n && arr[left] == 0) left++;
        while(right >= 0 && arr[right] == 0) right--;
        bool found_zero = false;   //flag to check if the segment of left and right contains any zero.
        for(long long i = left; i <= right; i++){
            if(arr[i] == 0) found_zero = true;
        }
        if(zeros == n) cout<<0<<endl;     //if all elements equal to 0 we do not need to do anything
        else if (found_zero == false) cout<<1<<endl;    //if there is only 1 segment without any zeros in between
        else cout<<2<<endl;   //we have found multiple segments of non zeros 
    }
    return 0;
}
