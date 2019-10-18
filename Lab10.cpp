#include<bits/stdc++.h>
#define size 4
using namespace std;
int solveMaze(int sR, int sC, int maze[size][size], int soln[size][size])
{
if ((sR == size - 1) && (sC == size - 1))
{
	      soln[sR][sC] = 1;
	      return 1;
	 }
	else
{
		soln[sR][sC] = 1;
		if ((sC < size - 1) && maze[sR][sC + 1] == 1 && solveMaze(sR, sC + 1, maze, soln))
{
		      return 1;
		}
		if ((sR < size - 1) && maze[sR + 1][sC] == 1 && solveMaze(sR + 1, sC, maze, soln))
{
		     return 1;
		}
		soln[sR][sC] = 0;
		return 0;
}
}
int main()
{
	int maze[size][size];
	    cout<<"Enter the maze values"<<endl;
	    for (int i = 0; i < size; ++i)
   {
	         for (int j = 0; j < size; ++j)
   	        {
		cin>>maze[i][j];
	        }
	   }
	  int soln[size][size] = {0};
  	  int sR = 0;
	  int sC = 0;
	  if(solveMaze(sR, sC, maze, soln))
{
	        cout<<"Solution is: "<<endl;
	        for (int i = 0; i < size; ++i)
       {
		for (int j = 0; j < size; ++j)
{
		     cout << soln[i][j]<<" ";
		}
		cout <<endl;
	       }
	    }
	    else
                 {
	        cout<<"No Solution"<<endl;
	    }
		return 0;
}
/*
OUTPUT:
Enter the maze values
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
Solution is:
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 1
*/