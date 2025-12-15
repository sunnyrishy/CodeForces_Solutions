Problem : https://codeforces.com/problemset/problem/1859/B

Here, we need to add the min of all the min of all the arrays and then we can sum the second_min of all the arrays except the array that has the lowerst min of all the arrays

First, we sum all the second_min
we delete the min of second_min
we find the min of all the elements

result = second_min - min(second_min) + min_element


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> second_min;
        ll lowest = INT_MAX;
        for(int i = 0; i < n; i++){
            ll m;
            cin>>m;
            vector<ll> arr(m);
            for(int j = 0; j < m; j++){
                cin>>arr[j];
            }
            sort(arr.begin(), arr.end());
            second_min.push_back(arr[1]);
            lowest = min(lowest, arr[0]);
        }
        
        sort(second_min.begin(), second_min.end());
        ll sum_of_second_min = accumulate(second_min.begin(), second_min.end(), 0LL);
        ll result = lowest + sum_of_second_min - second_min[0];
        cout<<result<<"\n";
    }
    return 0;
}
