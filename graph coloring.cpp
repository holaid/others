#include <iostream>
using namespace std;

int coloring(int g[5][5])
{
    int n=5;
    int color[n];
    int colored_node[n];
    for(int i=0; i<n; i++)  color[i]= 0; // 0 means available to color and 1 means not available
    for(int i=0; i<n; i++)  colored_node[i]= -1;    // means initially all vertex are not colored

    colored_node[0] = 0;        // initially coloring 0th vertex with color 0
    int min_color=1;
    for(int node=1; node < n; node++ )  // Row wise
    {
        //finding neigh and their color
         for(int i=0; i<n; i++)     //column Wise
         {
             if(g[node][i]==1) // equals to zero means that vertex is neigh of this vertex
             {
                if(colored_node[i] != -1 )  // means that neigh vertex is colored
                {
                    color[colored_node[i]] = 1;     //than made that color unavailable to color current node
                }
             }
         }
         int cr;
         for(cr=0; cr<n; cr++)
         {
             if(color[cr] == 0)
                break;
         }

         min_color=max(min_color,cr+1);

         colored_node[node] = cr;

         for(int i=0;i<n;i++)
         {
             color[i]=0;
         }
    }

    for(int i=0;i<n;i++)
    {
        cout<<"Color of vertex "<<i<<"= "<<colored_node[i]<<endl;
    }
    cout<<"\nminimun color needed="<<min_color<<endl;
    return 0;
}


int main ()
{
   int n=5;
    /*int g[5][5]={
        {0,1,1,0,0},
        {1,0,1,0,1},
        {1,1,0,0,1},
        {0,0,0,0,1},
        {0,1,1,1,0}} ;*/

    int g[5][5]={
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,1,0},
        {0,1,1,0,1},
        {0,0,0,1,0}} ;

    /*int g[5][5]={
        {0,1,1,1,1},
        {1,0,1,1,1},
        {1,1,0,1,1},
        {1,1,1,0,1},
        {1,1,1,1,0}} ; */ // All vertex are connected with each other

    /*int g[5][5]={
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0},
        {0,0,0,0,0}} ;  // All vertex are disconnected*/

        coloring(g);
}
