Problem : https://codeforces.com/problemset/problem/1666/D

D. Deletive Editing
time limit per test3 seconds
memory limit per test512 megabytes
Daisy loves playing games with words. Recently, she has been playing the following Deletive Editing word game with Daniel.

Daisy picks a word, for example, "DETERMINED". On each game turn, Daniel calls out a letter, for example, 'E', and Daisy removes the first occurrence of this letter from the word, getting "DTERMINED". On the next turn, Daniel calls out a letter again, for example, 'D', and Daisy removes its first occurrence, getting "TERMINED". They continue with 'I', getting "TERMNED", with 'N', getting "TERMED", and with 'D', getting "TERME". Now, if Daniel calls out the letter 'E', Daisy gets "TRME", but there is no way she can get the word "TERM" if they start playing with the word "DETERMINED".

Daisy is curious if she can get the final word of her choice, starting from the given initial word, by playing this game for zero or more turns. Your task it help her to figure this out.

Input
The first line of the input contains an integer n — the number of test cases (1≤n≤10000). The following n lines contain test cases.

Each test case consists of two words s and t separated by a space. Each word consists of at least one and at most 30 uppercase English letters; s is the Daisy's initial word for the game; t is the final word that Daisy would like to get at the end of the game.

Output
Output n lines to the output — a single line for each test case. Output "YES" if it is possible for Daisy to get from the initial word s to the final word t by playing the Deletive Editing game. Output "NO" otherwise.

Example
inputCopy
6
DETERMINED TRME
DETERMINED TERM
PSEUDOPSEUDOHYPOPARATHYROIDISM PEPA
DEINSTITUTIONALIZATION DONATION
CONTEST CODE
SOLUTION SOLUTION
outputCopy
YES
NO
NO
YES
NO
YES



--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------




  Intuition : We need to find the subsequence of t in s from the end.

  So to do that we can use a map to store the character to its freq mapping or a vector is also fine to use.

  and then check each character in s from the end, if this character is useful to us or not by looking at the freq of that character in the map
if it is > 1 then it is useful else we can ignore(delete) or for simplicity we mark it as '.' indicating that we dont need it anymore.

The reason for us to iterate from the end is because in the problem it is given that we need to remove the first occurances which is usually from the left so we are doing from right to left.


  

  Code : 



  #include<bits/stdc++.h>
using namespace std;

int main () {
    long long total;   //total test cases
    cin>>total;
    while(total--){
        string s, t;
        cin>>s;
        cin>>t;
        long long n = s.size();
        long long m = t.size();
        vector<long long>freq(26,0);    //map to store character to its freq mapping
        for(long long i = 0; i < m; i++){
            freq[t[i] - 'A']++;
        }
        for(long long i = n-1; i>= 0; i--){
            if(freq[s[i] - 'A'] > 0){
                freq[s[i] - 'A']--;     //cheching if that character is useful to us or not
            }
            else{
                s[i] = '.';     //marking it as '.' indicating that we do not need it anymore.
            }
        }
        string res = "";
        for(long long i = 0;  i< s.size(); i++){
            if(s[i] != '.'){
                res += s[i];  //if the remaining characters equal to t we are good to proceed 
            } 
        }
        if(res == t){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}
