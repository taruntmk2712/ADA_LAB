#include<iostream>
using namespace std;
int maze[10][10],sol[10][10];
int s=1;

bool isSafe(int x,int y)
{
    if(x>=0 && x<s && y>=0 && y<s && maze[x][y]==1)
        return true;
    return false;
}

bool solveMaze(int x,int y)
{
    if(x==s-1 && y==s-1)
    {
        sol[x][y]=1;
        return true;
    }
    if(isSafe(x,y))
    {
        sol[x][y]=1;
        if(solveMaze(x+1,y))
        {
            return true;
        }
        if(solveMaze(x,y+1))
        {
            return true;
        }
    }
    sol[x][y]=0;
    return false;
}
int main()
{
    int i,j;
    cout<<"Enter the maze size : ";
    cin>>s;
    cout<<"Enter the maze matrix : ";
    for(i=0;i<s;i++)
    {
        for(j=0;j<s;j++)
        {
            cin>>maze[i][j];
            sol[i][j]=0;
        }
    }
    if(solveMaze(0,0))
    {
        for(i=0;i<s;i++)
        {
            for(j=0;j<s;j++)
            {
                cout<<sol[i][j];
            }
            cout<<"\n";
        }
    }
    else
    {
        cout<<"No solution";
    }
    
}
