Problem : https://codeforces.com/problemset/problem/1890/A

b1 + b2 = b2 + b3, this means b1 and b3 must be equal (so, all the postions at odd must have same number)
b2 + b3 = b3 + b4, this menas b2 and b4 must be equal (so, all the positions at even must have same number)
if all the positions are covered by same number, then there is no issue


Conditions to check : 
if(number of unique elements is 1) then YES
if (number of unique elements is >= 3) then NO
if(number of unique elements is == 2) {
  check if their freq is equal then YES
  if their freq difference is 1, then YES, we can adjust with odd and even places
}

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
        map<ll,ll> mpp;
        for(ll i = 0;i < n; i++){
            cin>>arr[i];
            mpp[arr[i]]++;
        }
        if(mpp.size() >= 3 ) cout<<"NO"<<"\n";
        else {
            ll a = mpp.begin()->second;
            ll b = mpp.rbegin()->second;
            if(a == b){
                cout<<"YES"<<"\n";
            }
            else if (n % 2 == 1 && abs(a-b) <= 1){
                cout<<"YES"<<"\n";
            }
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}
