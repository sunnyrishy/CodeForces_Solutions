Problem : https://codeforces.com/problemset/problem/1606/A

A. AB Balance
time limit per test2 seconds
memory limit per test256 megabytes
You are given a string s of length n consisting of characters a and/or b.

Let AB(s) be the number of occurrences of string ab in s as a substring. Analogically, BA(s) is the number of occurrences of ba in s as a substring.

In one step, you can choose any index i and replace si with character a or b.

What is the minimum number of steps you need to make to achieve AB(s)=BA(s)?

Reminder:

The number of occurrences of string d in s as substring is the number of indices i (1≤i≤|s|−|d|+1) such that substring sisi+1…si+|d|−1 is equal to d. For example, AB(aabbbabaa)=2 since there are two indices i: i=2 where aabbbabaa and i=6 where aabbbabaa.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤1000). Description of the test cases follows.

The first and only line of each test case contains a single string s (1≤|s|≤100, where |s| is the length of the string s), consisting only of characters a and/or b.

Output
For each test case, print the resulting string s with AB(s)=BA(s) you'll get making the minimum number of steps.

If there are multiple answers, print any of them.

Example
inputCopy
4
b
aabbbabaa
abbb
abbaab
outputCopy
b
aabbbabaa
bbbb
abbaaa
Note
In the first test case, both AB(s)=0 and BA(s)=0 (there are no occurrences of ab (ba) in b), so can leave s untouched.

In the second test case, AB(s)=2 and BA(s)=2, so you can leave s untouched.

In the third test case, AB(s)=1 and BA(s)=0. For example, we can change s1 to b and make both values zero.

In the fourth test case, AB(s)=2 and BA(s)=1. For example, we can change s6 to a and make both values equal to 1.



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  Intuition : 

This is an observation based problem, If we clearly observe that whenever the starting and ending character of the string matches, then we do not need to do anything.

  Ex. abbbbaba
  In this ab = 2 and ba = 2

  In this way every string will have equal ab and ba if s[0] and s[n-1] matches.


  If s[0] and s[n-1] do not match and have different values all we need to do is to make them match and our job will be done.

To do that we will just change either the first or last character .
  if s[0] == 'a' s[0] = 'b';
  else s[0] = 'a'

this can be done with the last element as well.
if s[n-1] == 'a' s[n-1] = 'b'
else s[n-1] = 'a'



Code :  



#include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        long long n = s.size();
        
        if(s[0] == s[n-1]){
            
        }
        else{
            if(s[0] == 'a'){
                s[0] = 'b'; 
            }
            else{
                s[0] = 'a';
            }
        }
        cout<<s<<endl;
    }
    return 0;
}
