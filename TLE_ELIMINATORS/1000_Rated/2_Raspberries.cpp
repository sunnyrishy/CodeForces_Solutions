Problem : https://codeforces.com/problemset/problem/1883/C

🟢 Explanation of the Code
ll num_of_2 = 0;
ll ans = INT_MAX;


num_of_2 = how many elements in the array are even

ans = the minimum operations needed (initially a very large number)

🔍 Loop through each array element
for(ll i = 0; i < n; i++){
    if(arr[i] % 2 == 0) num_of_2++;
    if(arr[i] % k == 0) ans = 0;
    ans = min(ans, (k - arr[i] % k));
}

✔ 1. Count how many numbers are even
if(arr[i] % 2 == 0) num_of_2++;


Useful for the special case when k = 4, because:

If product must be divisible by 4 → you need:

one number divisible by 4, OR

two even numbers (two factors of 2)

✔ 2. If any number already divisible by k → answer = 0
if(arr[i] % k == 0) ans = 0;


Because the product will then automatically be divisible by k.

✔ 3. General case — compute operations needed for each element
ans = min(ans, (k - arr[i] % k));


To make arr[i] divisible by k:

cost[i] = (k - arr[i] % k)


You can choose any element, so we take the minimum.

This works for:

k = 2

k = 3

k = 5

But k = 4 needs special handling, so the code adds extra logic.

⭐ Special Case: k = 4
if(k == 4){
    if(num_of_2 == 0){
        ans = min(ans, 2ll);
    }
    else if (num_of_2 == 1){
        ans = min(ans, 1ll);
    }
    else ans = min(ans, 0ll);
}

Why is k = 4 special?

To have the product divisible by 4, you need at least 2 factors of 2.

Case-by-case:

🔵 Case 1: No even numbers (num_of_2 == 0)

Meaning all numbers are odd.

To get 2 factors of 2:

First increment: odd → even → 1 factor of 2

Second increment on the same or another number → another factor of 2

So answer = 2 operations

ans = min(ans, 2ll);

🟡 Case 2: Exactly one even number (num_of_2 == 1)

You already have one factor of 2.

Need one more factor of 2:

→ increment any odd number once → becomes even → gives the second factor of 2
Cost = 1

ans = min(ans, 1ll);

🟢 Case 3: Two or more even numbers (num_of_2 >= 2)

Two even numbers already give two factors of 2.

So product is automatically divisible by 4.

Cost = 0

ans = min(ans, 0ll);


=====================================================================================================================


#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll k;
        cin>>k;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) cin>>arr[i];
        ll num_of_2 = 0;
        ll ans = INT_MAX;
        for(ll i = 0; i < n; i++){
            if(arr[i] % 2 == 0) num_of_2++;
            if(arr[i] % k == 0) ans = 0;
            ans = min(ans, (k - arr[i] % k));
        }
        if(k == 4){
            if(num_of_2 == 0){
                ans = min(ans, 2ll);
            }
            else if (num_of_2 == 1){
                ans = min(ans, 1ll);
            }
            else ans = min(ans, 0ll);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
