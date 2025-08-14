Problem : https://codeforces.com/problemset/problem/1837/B


You are given a string s of length n, where each character is either < or >.

An array a consisting of n+1 elements is compatible with the string s if, for every i from 1 to n, the character si represents the result of comparing ai and ai+1, i. e.:

si is < if and only if ai<ai+1;
si is > if and only if ai>ai+1.
For example, the array [1,2,5,4,2] is compatible with the string <<>>. There are other arrays with are compatible with that string, for example, [13,37,42,37,13].

The cost of the array is the number of different elements in it. For example, the cost of [1,2,5,4,2] is 4; the cost of [13,37,42,37,13] is 3.

You have to calculate the minimum cost among all arrays which are compatible with the given string s.

Input
The first line contains one integer t (1≤t≤500) — the number of test cases.

Each test case consists of two lines:

the first line contains one integer n (1≤n≤100);
the second line contains the string s, consisting of n characters. Each character of s is either < or >.
Output
For each test case, print one integer — the minimum cost among all arrays which are compatible with the given string s.

Example
inputCopy
4
4
<<>>
4
>><<
5
>>>>>
7
<><><><
outputCopy
3
3
6
2
Note
In the first test case of the example, the array can be [13,37,42,37,13].

In the second test case of the example, the array can be [42,37,13,37,42].





--------------------------------------------------------------------------------------------------------------------------

In this problem we are asked to find the min numbers that are possible that matches with the given string s;

if s= <<>>
then one possible answer array could be 1<2<3>2>1;
if s = >>>>>
one possible answer array could be 6>5>4>3>2>1;


The logic to solve the prolem is to find the longest substring in the given string with the same sign as previous.
We need to fint the lenght of longest substring with either '<' or '>'

and then the longest substring +1 will be our answer.
is s.size() = 5 we need 6 elements so that is why we are adding +1 at the end.


Code: 






#include<bits/stdc++.h>
using namespace std;

int main () {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int maxx = 0;     // longest substring either '<' or '>'
        int countL = 0;   //used to have a count 
        int countR = 0;   //used to have a count
        int maxL = 0;     //max substring with '<' sign
        int maxR = 0;     //max substring with '>' sign
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '<'){
                maxR = max(maxR, countR);
                countR = 0;
                countL++;
            }
            else{
                maxL = max(maxL, countL);
                countL = 0;
                countR++;
            }
        }
        maxL = max(maxL, countL);
        maxR = max(maxR, countR);
        maxx = max(maxL, maxR) + 1;
        cout<<maxx<<endl;
    }
    return 0;
}
