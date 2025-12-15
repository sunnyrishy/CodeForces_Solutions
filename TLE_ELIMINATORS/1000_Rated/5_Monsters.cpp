Problem : https://codeforces.com/contest/1849/problem/B

We don't need to have the original health value of the monsters all we need to consider the last shot which they would die.
  so to do that we will simply do the modulus operation with k 

and to keep a track of their index in which they will start dying, we will store the index with a part of their health 
and then use a custom sort to sort based on the first value (the monster health), if the health is same we will choose the monster 
with least index, which is about to die earlier than the other monsters with same health.




#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n, k;
        cin>>n>>k;
        vector<pair<ll, ll>> arr(n);
        for(ll i = 0; i < n; i++){
            ll x;
            cin>>x;
            arr[i] = {x, i+1};
        }
        for(int i = 0; i < n; i++){
            arr[i].first = arr[i].first % k;
            if(arr[i].first == 0){
                arr[i].first = k;
            }
        }
        sort(arr.begin(), arr.end(), [](const pair<ll,ll>& a, const pair<ll,ll>& b){
            if(a.first != b.first){
                return a.first > b.first;
            }
            else return a.second < b.second;
        });

        for(auto it : arr){
            cout<<it.second<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
