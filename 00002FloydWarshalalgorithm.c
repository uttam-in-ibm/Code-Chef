#include <stdio.h>
#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })
int main() {
           int c,f,i,j;
           scanf("%d %d",&c,&f);
           int graph[c][c];
           for(i = 0;i < c;i++)
                   for(j = 0;j < c;j++)
                           graph[i][j] = 100000007;
           for(i = 0;i < c;i++)
                   graph[i][i] = 0;
           int x,y,p;
           for(i = 0;i < f;i++) {
                   scanf("%d %d %d",&x,&y,&p);
                   graph[x-1][y-1] = p;
                   graph[y-1][x-1] = p;
           }
           int dist[c][c],k;
           for(i = 0; i < c; i++)
               for (j = 0; j < c; j++)
                   dist[i][j] = graph[i][j];
           for(k = 0; k < c; k++) {
                 for(i = 0; i < c; i++) {
                       for(j = 0; j < c; j++) {
                             if(dist[i][k] + dist[k][j] < dist[i][j])
                                           dist[i][j] = dist[i][k] + dist[k][j];
                         }
                  }
           }
           int ans = 0;
           for(i = 0;i < c;i++)
                   for(j = 0;j < c;j++)
                           ans = max(ans,dist[i][j]);
           printf("%d",ans);
           return 0;
}
