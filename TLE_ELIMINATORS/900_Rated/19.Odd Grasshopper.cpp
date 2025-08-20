Problem : https://codeforces.com/problemset/problem/1607/B


B. Odd Grasshopper
time limit per test1 second
memory limit per test256 megabytes
The grasshopper is located on the numeric axis at the point with coordinate x0.

Having nothing else to do he starts jumping between integer points on the axis. Making a jump from a point with coordinate x with a distance d to the left moves the grasshopper to a point with a coordinate x−d, while jumping to the right moves him to a point with a coordinate x+d.

The grasshopper is very fond of positive integers, so for each integer i starting with 1 the following holds: exactly i minutes after the start he makes a jump with a distance of exactly i. So, in the first minutes he jumps by 1, then by 2, and so on.

The direction of a jump is determined as follows: if the point where the grasshopper was before the jump has an even coordinate, the grasshopper jumps to the left, otherwise he jumps to the right.

For example, if after 18 consecutive jumps he arrives at the point with a coordinate 7, he will jump by a distance of 19 to the right, since 7 is an odd number, and will end up at a point 7+19=26. Since 26 is an even number, the next jump the grasshopper will make to the left by a distance of 20, and it will move him to the point 26−20=6.

Find exactly which point the grasshopper will be at after exactly n jumps.

Input
The first line of input contains an integer t (1≤t≤104) — the number of test cases.

Each of the following t lines contains two integers x0 (−1014≤x0≤1014) and n (0≤n≤1014) — the coordinate of the grasshopper's initial position and the number of jumps.

Output
Print exactly t lines. On the i-th line print one integer — the answer to the i-th test case — the coordinate of the point the grasshopper will be at after making n jumps from the point x0.

Example
inputCopy
9
0 1
0 2
10 10
10 99
177 13
10000000000 987654321
-433494437 87178291199
1 0
-1 1
outputCopy
-1
1
11
110
190
9012345679
-87611785637
1
0
Note
The first two test cases in the example correspond to the first two jumps from the point x0=0.

Since 0 is an even number, the first jump of length 1 is made to the left, and the grasshopper ends up at the point 0−1=−1.

Then, since −1 is an odd number, a jump of length 2 is made to the right, bringing the grasshopper to the point with coordinate −1+2=1.





  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  Intuition : Find out the pattern for some n 
Say we start analysing the pattern considering x0 = 0 (origin)


0 1 2 3 4 5 6 7 8 9 10 11 12
0 -1 1 4 0 5 1 8 0 -9 1 12 0

  From the observation we can conclude these conditions : 
(n % 4 == 0) we land at 0.  //left
(n % 4 == 1) we land at -n.  //right
(n % 4 == 2) we land at 1.   //right
(n % 4 == 3) we land at n+1;  //left


There are two possibilities for us that we can start from an even index or from an odd index. 

Case 1 : If we start at even index :

        Consider your hand holding the number line and do the pattern left right right left we can see that we are still in the positive direction 
So the final position will be final position + start;

Case 2 : If we start at odd index : 

        Consider you hand holding the number line and do the pattern right left left right we can see that we are in the negative direction 
So the final position will be start- final postion;





Code : 


#include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        long long start, jumps;
        cin>>start>>jumps;
        
        long long final_pos = 0;
        if(jumps % 4 == 0) final_pos = 0;
        else if (jumps % 4 == 1) final_pos = -jumps;
        else if (jumps % 4 == 2) final_pos = 1;
        else if (jumps % 4 == 3) final_pos = jumps+1;
        
        if(start % 2 == 0){
            final_pos = final_pos + start;
        }
        else{
            final_pos = start - final_pos;
        }
        cout<<final_pos<<endl;
    }
    return 0;
}

        
