Problem : https://codeforces.com/problemset/problem/1543/A

A. Exciting Bets
time limit per test1 second
memory limit per test256 megabytes
Welcome to Rockport City!

It is time for your first ever race in the game against Ronnie. To make the race interesting, you have bet a dollars and Ronnie has bet b dollars. But the fans seem to be disappointed. The excitement of the fans is given by gcd(a,b), where gcd(x,y) denotes the greatest common divisor (GCD) of integers x and y. To make the race more exciting, you can perform two types of operations:

Increase both a and b by 1.
Decrease both a and b by 1. This operation can only be performed if both a and b are greater than 0.
In one move, you can perform any one of these operations. You can perform arbitrary (possibly zero) number of moves. Determine the maximum excitement the fans can get and the minimum number of moves required to achieve it.

Note that gcd(x,0)=x for any x≥0.

Input
The first line of input contains a single integer t (1≤t≤5⋅103) — the number of test cases.

The first and the only line of each test case contains two integers a and b (0≤a,b≤1018).

Output
For each test case, print a single line containing two integers.

If the fans can get infinite excitement, print 0 0.

Otherwise, the first integer must be the maximum excitement the fans can get, and the second integer must be the minimum number of moves required to achieve that excitement.

Example
inputCopy
4
8 5
1 2
4 4
3 9
outputCopy
3 1
1 0
0 0
6 3
Note
For the first test case, you can apply the first operation 1 time to get a=9 and b=6. It can be shown that 3 is the maximum excitement possible.

For the second test case, no matter how many operations you apply, the fans will always have an excitement equal to 1. Since the initial excitement is also 1, you don't need to apply any operation.

For the third case, the fans can get infinite excitement by applying the first operation an infinite amount of times.

For the fourth test case, you can apply the second operation 3 times to get a=0 and b=6. Since, gcd(0,6)=6, the fans will get an excitement of 6.



---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Intuition : The max value of gcd would be the difference of a and b (ignore sign). This would never exceed this value.

We are given with two operations 
I -> a++, b++, if we increase both the values the diffrence will be the same.
II -> a--, b--, same goes here.

  gcd(a, b) = gcd(a-b, b);

If a and b are equal then we would end up with gcd(0, b) and upon incresing the value of b it would reach too much.

SO when a nd b are equal the gcd will be 0 and moves = 0;

Code : 



#include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        long long a, b;
        cin>>a>>b;
        if(b > a){
            swap(a, b);    //always a > b
        }
        if(a == b){
            cout<<0<<" "<<0<<endl;
        }
        else{
            long long gcd = a-b;
            long long moves = min(b % gcd, gcd - b % gcd);    //b % gcd is bringing down b to close to gcd value
            cout<<gcd<<" "<<moves<<endl;                      //gcd - b % gcd = bringing b value to math the higher values of gcd
        }
    }
    return 0;
}
