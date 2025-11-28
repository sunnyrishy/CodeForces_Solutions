Problem : https://codeforces.com/problemset/problem/1903/A

Here, we need to check :
if the given array is already sorted then we can print yes,
  if the given array is not sorted then, if k > 1 then we can move any element to any position in the array using k = 2
                                          if k = 1 then we can't move the element from it's position



#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) cin>>arr[i];
        //check if it is sorted
        vector<ll> copy_arr(arr);
        sort(copy_arr.begin(), copy_arr.end());
        if(copy_arr == arr || k > 1) cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}
