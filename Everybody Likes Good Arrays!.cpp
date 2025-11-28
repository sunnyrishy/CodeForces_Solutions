Problem : https://codeforces.com/problemset/problem/1777/A

Parity is zero if the number is even, 1 if number is odd.
  We look for adjacnt numbers with same parity and count how many opeartions are needed (min)

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) cin>>arr[i];
        bool parity = 0;
        if(arr[0] % 2 == 0) parity = 0;
        else parity = 1;
        ll ans = 0;

        for(ll i = 1; i < n; i++){
            if(arr[i] % 2 == parity) ans++;
            else parity = !parity;
        }
        cout<<ans<<"\n";
    }
}
