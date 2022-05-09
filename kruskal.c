#include<stdio.h>
#include<stdlib.h>

int number;
int root[10];
int cost[10][10];
void doUnion(int root[], int v1, int v2) {
     int temp, i;
     temp = root[v2];
     for (i = 0; i < number; i++) {
        if (root[i] == temp) {
                root[i] = root[v1];
        }
     }          
}

 int v1, v2;
 
void findMinimum() {
        int minimum = 99;
        for (int t = 0; t < number; t++) {
                for (int k = 0; k < number; k++) {
                        if (cost[t][k] > 0 && cost[t][k] < minimum) {
                                minimum = cost[t][k];
                                v1 = t;
                                v2 = k;
                        }
                }
        }
}

int minimumCost;
int edgeWeight;

void kruskal() {
        for (int r = 0; r < number; r++) {
                root[r] = r;   
        }
        int count = 0;
        while (count != number - 1) {
            findMinimum();
            edgeWeight = cost[v1][v2];
            cost[v1][v2] = cost[v2][v1] = 0;
            if (root[v1] != root[v2]) {
                printf("(%d,%d)", v1, v2);
                doUnion(root, v1, v2); 
                minimumCost += edgeWeight;
                count++;    
            }   
        }
        printf("The minimum cost spanning tree=%d", minimumCost);
}


void main() {
        printf("Enter the number of vertices:");
        scanf("%d", &number); 
        printf("Enter costadjacency matrix:\n");
        for (int i = 0; i < number; i++) {
                for (int j = 0; j < number; j++) {
                        scanf("%d", &cost[i][j]);
                }
        }   
        
        for (int t = 0; t < number; t++) {
                for (int u = 0; u < number; u++) {
                        printf("%d\t", cost[t][u]);
                }
                printf("\n");
        }    
        kruskal();
}


