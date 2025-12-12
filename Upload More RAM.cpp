https://codeforces.com/problemset/problem/1987/A

We need to find the nth term of the AP series : 
Tn = a + (n-1)d;

here a = 1 (we place the ram in 1st second)
  d is the difference that is the window size i.e k;

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        cout<<((n-1)*(k))+1<<endl;
    }
    return 0;
}
