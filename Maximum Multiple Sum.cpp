Problem : https://codeforces.com/problemset/problem/1985/B

When we figure out that when n > 3 the answer is always 2
for n = 3, the result is 3

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n > 3){
            cout<<2<<"\n";
        }
        else cout<<n<<"\n";
    }
    return 0;
}
