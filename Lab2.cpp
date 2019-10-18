#include<iostream>
using namespace std;
class connected
{
    int adjacent[10][10],visited[10],v,n;
public:
        void input()
        {
            cout<<"enter the no. of components\n";
            cin>>n;
            for (int i=0;i<n;i++)
            {
                visited[i]=0;
             }
            cout<<"enter the adjacent matrix of graph\n";
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cin>>adjacent[i][j];
                 }
             }
         }

        void DFS(int v)
       {
            cout<<v+1<<",";
            visited[v]=1;
            for (int i=0;i<n;i++)
            {
                if(adjacent[v][i]==1 && visited[i]==0)
                {
                    DFS(i);
                 }
             }
        }
        void connected1()
       {
            for(int j=0;j<n;j++)
            {
                if(visited[j]==0)
                {
                    DFS(j);
                    cout<<"\n";
                 }
             }
        }
};
int main()
{
    connected c;
    c.input();
    c.connected1();
    return 0;
}


/*
OUTPUT:
enter the no. of components
6
enter the adjacent matrix of graph
0 0 1 0 0 0
0 0 0 0 0 1
1 0 0 0 1 0
0 0 0 0 0 0
0 0 1 0 0 0
0 1 0 0 0 0

0,2,4,
1,5,
3,
*/
