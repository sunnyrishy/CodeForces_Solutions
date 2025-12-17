https://codeforces.com/problemset/status?my=on

If the number of evens not match with even indices then we cant arrange the array, this happens with odd as well.
  Now we have pairs of elements that doesn't match with their parity, 
  Since a swap corrects two elements, so we will need not_matches/2 swaps here.
================================================================================================================

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        int even_indices = 0, odd_indeces = 0, even = 0, odd = 0;
        vector<int> arr(n);
        int not_matching = 0;
        for(int i = 0; i < n; i++){
          
            cin>>arr[i];
            if(i%2 == 0) even_indices++;
            else odd_indeces++;
            if(arr[i] % 2 == 0) even++;
            else odd++;
            if(i%2 != arr[i]%2) not_matching++;
        }

        if(even_indices != even || odd_indeces != odd){
            cout<<"-1"<<"\n";
            continue;
        }
        cout<<not_matching/2<<"\n";
    }
    return 0;
}
