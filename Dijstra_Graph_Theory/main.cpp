#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
#define I 32768
struct node
{
    int cost;
    int vertex;
    node(int c,int v)
    {
        this->cost=c;
        this->vertex=v;
    }
};
node min_cost(map<int,int> &m)
{
    map<int,int> ::iterator p=m.begin();
    node s(p->second,p->first);
    p++;
    for(;p!=m.end();p++)
    {
        if(s.cost>p->second)
        {
            s.cost=p->second;
            s.vertex=p->first;
        }
    }
    return s;
}
void Dijkstra(int start, int **a,int n)
{
    map<int,int> m;
    for(int j=0;j<n;j++)
    {
       if(j!=start)
        {
            m[j]=a[start][j];
        }
    }
    cout<<"costs from the vertex "<<start<<" is :\n";
    for(int i=0;i<n-1;i++)
    {
        node ans=min_cost(m);
        cout<<ans.vertex<<" "<<ans.cost<<endl;
        m.erase(ans.vertex);
        map<int,int> :: iterator x=m.begin();
        while(x!=m.end())
        {
            if(a[ans.vertex][x->first]+ans.cost<x->second)
                x->second=a[ans.vertex][x->first]+ans.cost;
            x++;
        }
    }
}
int main()
{
    int n=6;
    int **a;
    a=new int * [n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            a[i][j]=I;
        }
    }
    a[0][1]=2,a[0][2]=4;
    a[1][2]=1,a[1][3]=7;
    a[2][4]=3;
    a[3][5]=1;
    a[4][3]=2,a[4][5]=5;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==I)
                cout<<"_ ";
                else
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    Dijkstra(0,a,n);
    return 0;
}
