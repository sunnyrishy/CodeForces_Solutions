Problem : https://codeforces.com/problemset/problem/1374/B

Operations allowed : 
Multiply by 2
Divide by 6

Here we need to condiser the factors of that number. 
  If n = 2^a . 3^b . (something here) then we can never make it zero with out operations because dividing by 6 is like reducing a power of 2 and 3 not any other number
So n must be having only 2^a . 3^b

  if a > b, then dividing is not possible because each divide require one 2 and one 3
if three's are exhausted we only have op1 and will not take n to 1

  if a <= b then using op1 we can match a and b and use op2 to make n = 1

#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main () {
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll number_of_2 = 0;  //2^a
        ll number_of_3 = 0;  //3^b
        while(n > 0 && n % 3 == 0){
            number_of_3++;
            n = n/3;
        }
        while(n > 0 && n % 2 == 0){
            number_of_2++;
            n = n/2;
        }
        if(n > 1 || number_of_2 > number_of_3){   //if n has other factors (n> 1) or a > b then -1
            cout<<"-1"<<"\n";
        }
        else cout<<(number_of_3 - number_of_2) + number_of_3<<"\n";  // else match a with b using op 1 and then use op2
    }
    return 0;
}
