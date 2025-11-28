Problem : https://codeforces.com/problemset/problem/1901/A

for referece, draw the number line, we can understand that we need the max distance between the gas stations. 
  max(dist to first gas stations, distance between gas stations)
at the end the car needs to take a U-turn and it is mentioned that there is no gas stations at positon x, we need to calcualte double the distance



#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n, x;
        cin>>n>>x;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) cin>>arr[i];
        ll maxi = INT_MIN;
        for(ll i = 0; i < n; i++){
            if(i == 0) maxi = arr[0];   //dist to first gas station
            else maxi = max(maxi, arr[i] - arr[i-1]);  //max distance b/w gas stations
        }
        maxi = max(maxi, 2*(x - arr[n-1]));  //at the last stop, we need a U-turn and there is no gas stations at 'x'
        cout<<maxi<<"\n";
    }
    return 0;
}
