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

        int i = 0;
        int m = 0, e = 0, o = 0, w = 0;

        if(s[i] == 'm' || s[i] == 'M'){
            while(s[i] == 'm' || s[i] == 'M'){
                m = 1;
                i++;
            }
        }
        else{
            cout<<"NO"<<"\n";
            continue;
        }

        if(s[i] == 'e' || s[i] == 'E'){
            while(s[i] == 'e' || s[i] == 'E'){
                e = 1;
                i++;
            }
        }
        else{
            cout<<"NO"<<"\n";
            continue;
        }

        if(s[i] == 'o' || s[i] == 'O'){
            while(s[i] == 'o' || s[i] == 'O'){
                o = 1;
                i++;
            }
        }
        else{
            cout<<"NO"<<"\n";
            continue;
        }

        if(s[i] == 'w' || s[i] == 'W'){
            while(s[i] == 'w' || s[i] == 'W'){
                w = 1;
                i++;
            }
        }
        else{
            cout<<"NO"<<"\n";
            continue;
        }

        if(m == 1 && e == 1 && o == 1 && w == 1 && i == n){
            cout<<"YES"<<'\n';
        }
        else cout<<"NO"<<"\n";
    }
    return 0;
}
