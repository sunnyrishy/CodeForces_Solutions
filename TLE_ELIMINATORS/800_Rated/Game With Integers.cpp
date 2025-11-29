Problem : https://codeforces.com/problemset/problem/1899/A

Here, we need to consider 3 cases : 
n%3 == 0 (here, if he do +1, then Vova will do -1 and vice versa and ultimately vova wins )
  n%3 ==1 (here vanys can do -1 and win)
  n%3 ==2 (here vanya can do +1 and win)

  #include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n%3 == 0) {
            cout<<"Second"<<"\n";
        }
        else {
            cout<<"First"<<"\n";
        }
    }
    return 0;
}
