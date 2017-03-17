#include <iostream>
using namespace std;

int Bellman_Ford(int G[500][500] , int V, int E, int edge[500][2])
{
    int i,u,v,k,distance[500],S,flag=1;

    for(i=0;i<V;i++)
        distance[i] = 1000 ;

    cout<<"\nEnter source (S.no. of the vertex): ";
    cin>>S;
    distance[S-1]=0 ;

    for(i=0;i<V-1;i++)
    {
        for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                distance[v] = distance[u] + G[u][v];
        }
    }

    for(k=0;k<E;k++)
        {
            u = edge[k][0] , v = edge[k][1] ;
            if(distance[u]+G[u][v] < distance[v])
                flag = 0 ;
        }

    if(flag)
            for(i=0;i<V;i++)
                cout<<"\nVertex "<<i+1<<" -> cost = "<<  distance[i] <<endl;

    return flag;

}

int main()
{
    int V,edge[500][2],G[500][500],i,j,k=0;
    cout<<"BELLMAN FORD\n";
    cout<<"Enter no. of vertices: ";
    cin>>V;
    cout<<"Enter graph in matrix form:\n";
    for(i=0;i<V;i++)
        for(j=0;j<V;j++)
        {
            cin>>G[i][j];
            if(G[i][j]!=0)
                edge[k][0]=i,edge[k++][1]=j;
        }

    if(Bellman_Ford(G,V,k,edge))
        cout<<"\nNo negative weight cycle exists\n";
    else cout<<"\nNegative weight cycle exists\n";

    return 0;
}
