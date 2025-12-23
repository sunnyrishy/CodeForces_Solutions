#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll n; cin>>n;
    vector<ll> a(n);
    for(ll i = 0; i < n; i++) cin>>a[i];
    ll m; cin>>m;
    vector<ll>b(m);
    for(ll i = 0; i < m; i++){
        cin>>b[i];
    }
    vector<ll>pre_comp(n+1);
    for(ll i = 0; i < n; i++){
        pre_comp[a[i]] = i;
    }
    ll front = 0;
    ll back = 0;
    for(int i = 0; i < m; i++){
        front += pre_comp[b[i]] +1;
        back += n - (pre_comp[b[i]] +1) +1;
    }
    cout<<front<<" "<<back<<endl;
    return 0;
}
