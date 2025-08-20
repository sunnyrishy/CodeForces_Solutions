Problem : https://codeforces.com/problemset/problem/1593/B

B. Make it Divisible by 25
time limit per test1 second
memory limit per test256 megabytes
It is given a positive integer n. In 1 move, one can select any single digit and remove it (i.e. one selects some position in the number and removes the digit located at this position). The operation cannot be performed if only one digit remains. If the resulting number contains leading zeroes, they are automatically removed.

E.g. if one removes from the number 32925 the 3-rd digit, the resulting number will be 3225. If one removes from the number 20099050 the first digit, the resulting number will be 99050 (the 2 zeroes going next to the first digit are automatically removed).

What is the minimum number of steps to get a number such that it is divisible by 25 and positive? It is guaranteed that, for each n occurring in the input, the answer exists. It is guaranteed that the number n has no leading zeros.

Input
The first line contains one integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

Each test case consists of one line containing one integer n (25≤n≤1018). It is guaranteed that, for each n occurring in the input, the answer exists. It is guaranteed that the number n has no leading zeros.

Output
For each test case output on a separate line an integer k (k≥0) — the minimum number of steps to get a number such that it is divisible by 25 and positive.

Example
inputCopy
5
100
71345
3259
50555
2050047
outputCopy
0
3
1
3
2
Note
In the first test case, it is already given a number divisible by 25.

In the second test case, we can remove the digits 1, 3, and 4 to get the number 75.

In the third test case, it's enough to remove the last digit to get the number 325.

In the fourth test case, we can remove the three last digits to get the number 50.

In the fifth test case, it's enough to remove the digits 4 and 7.






--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



Intuition : 


When we look at the divisibility rule for 25 it is observed that number os divisible by 25 if the last two digits of number is either 
  {00, 25, 50, 75}

The given input n is of the order 10^18 which is very high.
  So simply we can consider taking the input as a string and then our job will be easy to handle the operations.


  All we need to do is the compute the operations required to make the given number ending with 00 or 25 or 50 or 75
  and take the min of it. 




  Code : 

#include<bits/stdc++.h>
using namespace std;

long long solve(string s){
    vector<string> endings = {"00", "25", "50", "75"};   //endings array
    int n = s.size();
    int ans = INT_MAX;
    
    for(auto &end : endings){ // each entry in the vector endings is considered as end iterator
        int j = 1;
        int ops = 0;    //operations required
        for(int i = n-1; i >= 0; i--){
            if(s[i] == end[j]){
                j--;
                if(j < 0){
                    ans = min(ans, ops);   // min ops required for conveting the number ending into 00 or 25 or 50 or 75
                    break;  
                }
            }
            else{
                ops++;
            }
        }
    }
    return ans;
}

int main () {
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        cout<<solve(s)<<endl;
    }
    return 0;
}
