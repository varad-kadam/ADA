#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int n;
int min_cost = INT_MAX;
int path_taken[10];
bool visited[10];

void adjprint(int adj[n][n])
{
    printf("\nThe adjacency matrix is --\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int firstMin(int adj[n][n], int i)
{
    int min = INT_MAX;
    for (int k = 0; k < n; k++)
    {
        if (adj[i][k] < min && i != k)
        {
            min = adj[i][k];
        }
    }
    return min;
}

int secondMin(int adj[n][n], int i)
{
    int first = INT_MAX, second = INT_MAX;
    for (int j = 0; j < n; j++)
    {
        if (i == j)
        {
            continue;
        }
        if (adj[i][j] <= first)
        {
            second = first;
            first = adj[i][j];
        }
        else if (adj[i][j] <= second && adj[i][j] != first)
        {
            second = adj[i][j];
        }
    }
    return second;
}

void copyToFinal(int curr_path[])
{
    for (int i = 0; i < n; i++)
        path_taken[i] = curr_path[i];
    path_taken[n] = curr_path[0];
}

void TSPRec(int adj[n][n], int curr_bound, int curr_weight, int level, int curr_path[])
{
    if (level == n)
    {
        if (adj[curr_path[level - 1]][curr_path[0]] != 0)
        {
            int curr_res = curr_weight + adj[curr_path[level - 1]][curr_path[0]];
            if (curr_res < min_cost)
            {
                copyToFinal(curr_path);
                min_cost = curr_res;
            }
        }
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (adj[curr_path[level - 1]][i] != 0 && visited[i] == false)
        {
            int temp = curr_bound;
            curr_weight += adj[curr_path[level - 1]][i];
            if (level == 1)
            {
                curr_bound -= ((firstMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);
            }
            else
            {
                curr_bound -= ((secondMin(adj, curr_path[level - 1]) + firstMin(adj, i)) / 2);
            }
            if (curr_bound + curr_weight < min_cost)
            {
                curr_path[level] = i;
                visited[i] = true;
                TSPRec(adj, curr_bound, curr_weight, level + 1, curr_path);
            }
            curr_weight -= adj[curr_path[level - 1]][i];
            curr_bound = temp;
            memset(visited, false, sizeof(visited));
            for (int j = 0; j <= level - 1; j++)
            {
                visited[curr_path[j]] = true;
            }
        }
    }
}

void TSP(int adj[n][n])
{
    int curr_path[n + 1];
    int curr_bound = 0;
    memset(curr_path, -1, sizeof(curr_path));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
    {
        curr_bound += (firstMin(adj, i) + secondMin(adj, i));
    }
    if (curr_bound == 1)
    {
        curr_bound = curr_bound / 2 + 1;
    }
    else
    {
        curr_bound = curr_bound / 2;
    }
    visited[0] = true;
    curr_path[0] = 0;
    TSPRec(adj, curr_bound, 0, 1, curr_path);
}

int main()
{
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    int ch, adj[n][n];
    printf("Is the graph\n1.Undirected\n2.Directed\n");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
    {
        for (int i = 0; i < n; i++)
        {
            printf("\nInput the cities adjacent to city %d", i + 1);
            for (int j = i; j < n; j++)
            {
                if (i == j)
                {
                    adj[i][j] = adj[j][i] = 0;
                }
                else
                {
                    printf("\nEnter the cost of going from city %d to city %d: ", i + 1, j + 1);
                    scanf("%d", &adj[i][j]);
                    adj[j][i] = adj[i][j];
                }
            }
            printf("\n");
        }
        adjprint(adj);
        break;
    }
    case 2:
    {
        for (int i = 0; i < n; i++)
        {
            printf("\nInput the cities adjacent to city %d", i + 1);
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    adj[i][j] = 0;
                }
                else
                {
                    printf("\nEnter the cost of going from city %d to city %d: ", i + 1, j + 1);
                    scanf("%d", &adj[i][j]);
                }
            }
            printf("\n");
        }
        adjprint(adj);
        break;
    }
    default:
    {
        printf("Wrong input");
        break;
    }
    }
    TSP(adj);
    printf("Minimum cost: %d\n", min_cost);
    printf("Path Taken: ");
    for (int i = 0; i <= n; i++)
    {
        printf("%d ", path_taken[i]);
    }
    return 0;
}
