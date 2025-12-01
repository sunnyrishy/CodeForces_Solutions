Problem : https://codeforces.com/problemset/problem/1913/B

As long as there is '1', we can change 0 to 1.
  As long as there is '0', we can change 1 to 0

#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll zeros = 0;
        ll ones = 0;
        for(char c : s){
            if(c == '0') zeros++;
            else ones++;
        }
        ll len_t = 0;
        for(char c : s){
            if(c == '0' && ones > 0){
                ones--;
                len_t++;
            }
            else if (c == '1' && zeros > 0){
                zeros--;
                len_t++;
            }
            else break;
        }
        cout<<s.size()-len_t<<"\n";
    }
    return 0;
}
