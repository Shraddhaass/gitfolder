#include<stdio.h>
#include<stdlib.h>

void document(int root[],int v1,int v2)
{
int temp,i;
temp=root[v2];
for(i=0;i<n;i++)
{
if(root[i]==temp)
{
 root[i]=root[v1];
}
}
}
void kruskal()
{
int i,edgewt;
int root[n];
for(i=0;i<n;i++)
root[i]=i;
printf("\n Edge of min-cost spanning tree are");
i=0;
while(i!=n-1)
{
findMin();
edgewt=cost[v1][v2];
cost[v1][v2]=cost[v2][v1]=0;
if(root[v1]!=root[v2]
{
printf("\(%d,%d)",v1,v2);
doUnion(root,v1,v2);
i++;
}
}
printf("\n Cost of min-cost spanning tree=%d",mincost);
}
}
void main()
{
int i,j,n,cost[10][10];
printf("Enter the number of vertices");
scanf("%d",&n);
printf("Enter undirected graph as adjacency matrix\n");
for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
  scanf("%d\t",&cost[i][j])
}
}
}

