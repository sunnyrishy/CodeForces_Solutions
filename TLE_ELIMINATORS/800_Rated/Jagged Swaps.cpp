Problem : https://codeforces.com/problemset/problem/1896/A

The term permutation in this problem refer to an n-sized array containing numbers form 1 to n and the numbers are unique

From observation, we can see that first index of the array can't be shifted.
  So to make the array sorted, we need to check if the first index is 1 or not.
  If arr[0] == 1 then YES else NO

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
        if(arr[0] == 1) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}
