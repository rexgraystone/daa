/*  
    5. Write a program to find the Minimum Cost Spanning Tree using Prim's algorithm.
*/

#include <stdio.h>
#include <stdbool.h>
# define INF 99999999 //infinity

int main()
{
    int i, j, e, g[6][6], selected[6], n, x, y, min;
    printf("Enter the number of vertices less than 6: ");
    scanf("%d", &n);
    printf("Input the weighted graph in terms of matrix: \n");
    memset(selected, false, sizeof(selected));
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    memset(selected, false, sizeof(selected));
    int e = 0;
    selected[0] = true;
    printf("Edge \tWeight\n");
    while(e<(n-1))
    {
        int min = INF;
        int x = 0;
        int y = 0;
        for(int i=0; i<n; i++)
        {
            if(selected[i])
            {
                for(int j=0; j<n; j++)
                {
                    if(!selected[j] && g[i][j])
                    {
                        if(min>g[i][j])
                        {
                            min = g[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }
    }
    printf("%d - %d \t%d", x, y, g[x][y]);
    selected[y] = true;
    return 0;
}