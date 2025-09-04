Problem : https://codeforces.com/problemset/problem/1537/B

B. Bad Boy
time limit per test1 second
memory limit per test256 megabytes
Riley is a very bad boy, but at the same time, he is a yo-yo master. So, he decided to use his yo-yo skills to annoy his friend Anton.

Anton's room can be represented as a grid with n rows and m columns. Let (i,j) denote the cell in row i and column j. Anton is currently standing at position (i,j) in his room. To annoy Anton, Riley decided to throw exactly two yo-yos in cells of the room (they can be in the same cell).

Because Anton doesn't like yo-yos thrown on the floor, he has to pick up both of them and return back to the initial position. The distance travelled by Anton is the shortest path that goes through the positions of both yo-yos and returns back to (i,j) by travelling only to adjacent by side cells. That is, if he is in cell (x,y) then he can travel to the cells (x+1,y), (x−1,y), (x,y+1) and (x,y−1) in one step (if a cell with those coordinates exists).

Riley is wondering where he should throw these two yo-yos so that the distance travelled by Anton is maximized. But because he is very busy, he asked you to tell him.

Input
The first line contains a single integer t (1≤t≤104) — the number of test cases. Then t test cases follow.

The only line of each test case contains four integers n, m, i, j (1≤n,m≤109, 1≤i≤n, 1≤j≤m) — the dimensions of the room, and the cell at which Anton is currently standing.

Output
For each test case, print four integers x1, y1, x2, y2 (1≤x1,x2≤n, 1≤y1,y2≤m) — the coordinates of where the two yo-yos should be thrown. They will be thrown at coordinates (x1,y1) and (x2,y2).

If there are multiple answers, you may print any.

Example
inputCopy
7
2 3 1 1
4 4 1 2
3 5 2 2
5 1 2 1
3 1 3 1
1 1 1 1
1000000000 1000000000 1000000000 50
outputCopy
1 2 2 3
4 1 4 4
3 1 1 5
5 1 1 1
1 1 2 1
1 1 1 1
50 1 1 1000000000
Note


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  In this problem they were asking to make the person trael more so that the distance covered by him will be maximized.
  In order to cover the max distance, the yo-yo has to be placed at the corners.
  If we place one yo-yo at one corner of the grid then the other one should be placed diagonally opposite to that.

  Let i,j be the initial position of the person then if we place yo-yo at one corner then he needs to cover the steps to reach there 
and then come back in the same path covering his initial position and then start travelling to cover the second yo-yo which is placed at another corner.

The position of the yo-yo will be either at (1,1) & (n,m) or (1,m) & (n,1)
  The total distance coverby the person collecting the yo-yo is 2*(m-1) + 2*(n-1)


Code : 


#include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        long long n, m, i ,j;
        cin>>n>>m>>i>>j;
        cout<<1<<" "<<1<<" "<<n<<" "<<m<<" "<<endl;    //printing the first and last corner. anothr option will also works
    }
    return 0;
}
