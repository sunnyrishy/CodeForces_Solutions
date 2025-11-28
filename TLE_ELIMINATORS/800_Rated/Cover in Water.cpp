Problem : https://codeforces.com/problemset/problem/1900/A

Here, we need to consider is that whern there is an empty cell covered with water on both sides, then it will be filled with water automatically.
  So, we have unlimited access to water (keep this in mind)

So If so ever, we find 3 consecutive empty slots, then using 2 operations of action 1 we can fill all the empty cells using action 2
if we were not able to find 3 empty slots, then operations = number of empty slots (each slot is one operation)


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        bool three_empty_cells = false;
        ll empty_cells = 0;
        for(ll i = 0; i < n; i++){
            if(s[i] == '.' && i+1 < n && s[i+1] == '.' && i+2 < n && s[i+2] == '.'){  //unlimited access to water
                three_empty_cells = true;
            }
            if(s[i] == '.') empty_cells++;
        }
        if(three_empty_cells) cout<<"2"<<"\n";
        else cout<<empty_cells<<"\n";
    }
    return 0;
}
