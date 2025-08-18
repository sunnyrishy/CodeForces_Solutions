Problem : https://codeforces.com/problemset/problem/1665/B



B. Array Cloning Technique
time limit per test1 second
memory limit per test256 megabytes
You are given an array a of n integers. Initially there is only one copy of the given array.

You can do operations of two types:

Choose any array and clone it. After that there is one more copy of the chosen array.
Swap two elements from any two copies (maybe in the same copy) on any positions.
You need to find the minimal number of operations needed to obtain a copy where all elements are equal.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer n (1≤n≤105) — the length of the array a.

The second line of each test case contains n integers a1,a2,…,an (−109≤ai≤109) — the elements of the array a.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case output a single integer — the minimal number of operations needed to create at least one copy where all elements are equal.

Example
inputCopy
6
1
1789
6
0 1 3 3 7 0
2
-1000000000 1000000000
4
4 3 2 1
5
2 5 7 6 3
7
1 1 1 1 1 1 1
outputCopy
0
6
2
5
7
0
Note
In the first test case all elements in the array are already equal, that's why the answer is 0.

In the second test case it is possible to create a copy of the given array. After that there will be two identical arrays:

[ 0 1 3 3 7 0 ] and [ 0 1 3 3 7 0 ]

After that we can swap elements in a way so all zeroes are in one array:

[ 0 0– 0– 3 7 0 ] and [ 1– 1 3 3 7 3– ]

Now let's create a copy of the first array:

[ 0 0 0 3 7 0 ], [ 0 0 0 3 7 0 ] and [ 1 1 3 3 7 3 ]

Let's swap elements in the first two copies:

[ 0 0 0 0– 0– 0 ], [ 3– 7– 0 3 7 0 ] and [ 1 1 3 3 7 3 ].

Finally, we made a copy where all elements are equal and made 6 operations.

It can be proven that no fewer operations are enough.



------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Intuition : 

Here I have implemented this in this way : 
I used a map that stores the element with the frequency. 
  So that we can proceed with the element with highest frequency because that takes the least operations. [used ordered map]

  Once we get the element with highest freq now it is time to calculate the number of operations it takes to make an array completely filled with a single element

Remember : Copy operations contributes +1
          Swapping each element contributes to +1

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
        for(long long i = 0; i < n; i++){
            cin>>arr[i];                        //storing input
        }
        map<long long, long long>mpp;          //ordered_map
        for(long long i = 0; i < n; i++){
            mpp[arr[i]]++;                     //input to map.  {element, freq}
        }
        long long max_freq = 0;               //highest freq element
        for(auto &it : mpp){
            max_freq = max(max_freq, it.second);
        }
        long long ops = 0;
        long long freq = max_freq;            //freq represents the freq of the highest occuring element at this moment 
        while(freq < n){                   //while the array is completely filled
            ops++;                         //this is a copy operaton. [1 copy = +1 ops]
            long long add = min(n-freq, freq);      //this is swap opeartions
            ops += add;                  //increase operations
            freq += add;                //increase the value of freq of our highest occuring element
        }
        cout<<ops<<endl;
    }
    return 0;
}
  
