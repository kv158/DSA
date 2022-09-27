#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int a[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};
// for a graph
//                             0---1
//                             | \ |
//                             2---3
//                              \ /
//                               4
//                              / \
//                             5   6

void reset()
{
    for (int k = 0; k < 7; k++)
    {
        visited[k] = 0;
    }
}
void dfs(int i)
{

    int j;
    printf("%d", i);
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !visited[j])
        {
            dfs(j);
        }
    }
}

int main()
{
    dfs(0);
    reset();
    printf("\n");

    dfs(1);
    reset();
    printf("\n");

    dfs(5);
    reset();
    printf("\n");

    return 0;
}