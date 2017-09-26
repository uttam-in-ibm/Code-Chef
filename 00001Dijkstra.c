// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph
  
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[],int V)
{
   // Initialize min value
   int min = INT_MAX, min_index,v;
  
   for (v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  
// A utility function to print the constructed distance array
int printSolution(int dist[], int n,int V)
{
	int i;
   //printf("Vertex   Distance from Source ");
   for (i = 0; i < V; i++){
   	if(i==V-1)
   	//printf("\n%d to %d", i, dist[i]);
   	printf("%d", dist[i]);
   }
      
}
  
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int V,int graph[V][V], int src)
{
     int dist[V],i,count;     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
  
     bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
  
     // Initialize all distances as INFINITE and stpSet[] as false
     for ( i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
  
     // Distance of source vertex from itself is always 0
     dist[src] = 0;
  
     // Find shortest path for all vertices
     for (count = 0; count < V-1; count++)
     {
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet,V),v;
  
       // Mark the picked vertex as processed
       sptSet[u] = true;
  
       // Update dist value of the adjacent vertices of the picked vertex.
       for (v = 0; v < V; v++)
  
         // Update dist[v] only if is not in sptSet, there is an edge from 
         // u to v, and total weight of path from src to  v through u is 
         // smaller than current value of dist[v]
         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }
  
     // print the constructed distance array
     printSolution(dist, V,V);
}
  
// driver program to test above function
int main()
{
	int V;
   /* Let us create the example graph discussed above */
   int F,C,i,a,b,c;
   scanf("%d",&C);
   scanf("%d",&F);
   int graph[C][C];
   for(i=0;i<F;i++){
   	scanf("%d %d %d",&a,&b,&c);
   	graph[a-1][b-1]=graph[b-1][a-1]=c;
   }  
    dijkstra(C,graph, 0);
  
    return 0;
}
