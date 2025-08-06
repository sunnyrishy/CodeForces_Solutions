Problem : https://codeforces.com/problemset/problem/1869/A

A. Make It Zero
time limit per test1 second
memory limit per test256 megabytes
During Zhongkao examination, Reycloer met an interesting problem, but he cannot come up with a solution immediately. Time is running out! Please help him.

Initially, you are given an array a consisting of n≥2 integers, and you want to change all elements in it to 0.

In one operation, you select two indices l and r (1≤l≤r≤n) and do the following:

Let s=al⊕al+1⊕…⊕ar, where ⊕ denotes the bitwise XOR operation;
Then, for all l≤i≤r, replace ai with s.
You can use the operation above in any order at most 8 times in total.

Find a sequence of operations, such that after performing the operations in order, all elements in a are equal to 0. It can be proven that the solution always exists.

Input
The first line of input contains a single integer t (1≤t≤500) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer n (2≤n≤100) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (0≤ai≤100) — the elements of the array a.

Output
For each test case, in the first line output a single integer k (0≤k≤8) — the number of operations you use.

Then print k lines, in the i-th line output two integers li and ri (1≤li≤ri≤n) representing that you select li and ri in the i-th operation.

Note that you do not have to minimize k. If there are multiple solutions, you may output any of them.

Example
inputCopy
6
4
1 2 3 0
8
3 1 4 1 5 9 2 6
6
1 5 4 1 4 7
5
0 0 0 0 0
7
1 1 9 9 0 1 8
3
100 100 0
outputCopy
1
1 4
2
4 7
1 8
6
1 2
3 4
5 6
1 3
4 6
1 6
0
4
1 2
6 7
3 4
6 7
1
1 2
Note
In the first test case, since 1⊕2⊕3⊕0=0, after performing the operation on segment [1,4], all the elements in the array are equal to 0.

In the second test case, after the first operation, the array becomes equal to [3,1,4,15,15,15,15,6], after the second operation, the array becomes equal to [0,0,0,0,0,0,0,0].

In the third test case:

Operation	a before		a after
1	[1,5––––,4,1,4,7]	→	[4,4,4,1,4,7]
2	[4,4,4,1––––,4,7]	→	[4,4,5,5,4,7]
3	[4,4,5,5,4,7––––]	→	[4,4,5,5,3,3]
4	[4,4,5––––––,5,3,3]	→	[5,5,5,5,3,3]
5	[5,5,5,5,3,3––––––]	→	[5,5,5,5,5,5]
6	[5,5,5,5,5,5––––––––––––]	→	[0,0,0,0,0,0]
In the fourth test case, the initial array contains only 0, so we do not need to perform any operations with it.





------------------------------------------------------------------------------------------------------------------------------------------------------------

  Intuition : Recall the XOR properties

a ^ a = 0;
a ^ 0 = 0;
0 ^ 0 = 0;

Given a n sized array, if n is even then we can do XOR from 1 to n-1 say the result is 's' then we replace every ai from 1 to n with s. Now a will look like 
a = [s,s,s,s,s,s];
Now we do one more XOR from 1 to n we will end up making every element '0';


If n is odd, then we can do XOR from 1 to n-1 and then from 1 to n-1. This will make the 1 to n-1 part as 0.
Then we can perform XOR from n-1 to n and then n-1 to n we will end up making the right most part as 0.



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
        if(n % 2 == 0){
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n<<endl;
        }
        else{
            cout<<4<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            cout<<n-1<<" "<<n<<endl;
        }
    }
    return 0;
}
