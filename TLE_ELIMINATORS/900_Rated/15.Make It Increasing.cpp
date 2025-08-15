Problem : https://codeforces.com/problemset/problem/1675/B

B. Make It Increasing
time limit per test2 seconds
memory limit per test256 megabytes
Given n integers a1,a2,…,an. You can perform the following operation on them:

select any element ai (1≤i≤n) and divide it by 2 (round down). In other words, you can replace any selected element ai with the value ⌊ai2⌋ (where ⌊x⌋ is – round down the real number x).
Output the minimum number of operations that must be done for a sequence of integers to become strictly increasing (that is, for the condition a1<a2<⋯<an to be satisfied). Or determine that it is impossible to obtain such a sequence. Note that elements cannot be swapped. The only possible operation is described above.

For example, let n=3 and a sequence of numbers [3,6,5] be given. Then it is enough to perform two operations on it:

Write the number ⌊62⌋=3 instead of the number a2=6 and get the sequence [3,3,5];
Then replace a1=3 with ⌊32⌋=1 and get the sequence [1,3,5].
The resulting sequence is strictly increasing because 1<3<5.

Input
The first line of the input contains an integer t (1≤t≤104) — the number of test cases in the input.

The descriptions of the test cases follow.

The first line of each test case contains a single integer n (1≤n≤30).

The second line of each test case contains exactly n integers a1,a2,…,an (0≤ai≤2⋅109).

Output
For each test case, print a single number on a separate line — the minimum number of operations to perform on the sequence to make it strictly increasing. If a strictly increasing sequence cannot be obtained, print "-1".

Example
inputCopy
7
3
3 6 5
4
5 3 2 1
5
1 2 3 4 5
1
1000000000
4
2 8 7 5
5
8 26 5 21 10
2
5 14
outputCopy
2
-1
0
0
4
11
0
Note
The first test case is analyzed in the statement.

In the second test case, it is impossible to obtain a strictly increasing sequence.

In the third test case, the sequence is already strictly increasing.




---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


We were asked to make the array strictly increeasing by doing only a specific operation mentioned in the problem statement.

The optimal way to solve is to iterate the array from the reverse order and upon iterating if we found any arr[i] >= arr[i+1] 
then we divide it until it is brought down the arr[i+1] and this process goes on till we completely iterate the array.

At any point if we encounter two '0' continuously then we can't modify the array to satisfy the given conditions. 
Then we return -1;



Code : 


#include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long > arr(n);
        for(long long i = 0; i < n; i++) cin>>arr[i];
        
        int ops = 0;
        for(int i = n-2; i >= 0; i--){
            while(arr[i] >= arr[i+1]){.   //if any arr[i] >= arr[i+1]
                ops++;
                arr[i] = arr[i]/2;      //divide until it id brought down to arr[i+1]
                if(arr[i] == 0) break;
            }
            if(arr[i] == 0 && arr[i+1] == 0){.  //if we have two zeros it cant be solved.
                ops = -1;
                break;
            }
        }
        cout<<ops<<endl;
    }
    return 0;
}
