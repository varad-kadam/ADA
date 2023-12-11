#include <iostream>
using namespace std;
class graph
{
    int cost[10][10], n;

public:
    void getgraph();
    void display();
    void prim();
};
void graph::getgraph()
{
    cout << "enter no. of vertices\n";
    cin >> n;
    int i, j;
    char c;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cost[i][j] = 999;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
        {
            if (cost[i][j] == 999)
            {
                cout << "is edge (" << i << "," << j << ") present (y/n)?\n";
                cin >> c;
                if (c == 'y')
                {
                    cout << "enter weight of edge \n";
                    cin >> cost[i][j];
                    cost[j][i] = cost[i][j];
                }
            }
        }
    display();
}
void graph::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << "\n";
    }
}
void graph::prim()
{
    int min = 999, t[n][n], near[n], i, j, k, u, v, mincost = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            if (min > cost[i][j])
            {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    t[0][0] = u;
    t[0][1] = v;
    for (i = 0; i < n; i++)
    {
        if (cost[i][v] < cost[i][u])
            near[i] = v;
        else
            near[i] = u;
    }
    mincost = min;
    near[u] = -1;
    near[v] = -1;
    for (i = 1; i < n - 1; i++)
    {
        min = 999;
        for (j = 0; j < n; j++)
        {
            if ((near[j] != -1) && (cost[near[j]][j] < min))
            {
                min = cost[j][near[j]];
                u = j;
                v = near[j];
            }
        }
        t[i][0] = v;
        t[i][1] = u;
        mincost = mincost + cost[u][v];
        near[u] = -1;
        for (k = 0; k < n; k++)
        {
            if ((near[k] != -1) && (cost[k][near[k]] > cost[k][u]))
                near[k] = u;
        }
    }
    cout << "minimum cost is : " << mincost << endl;
    cout << "minimum spanning tree contains following edges\n";
    for (i = 0; i < n - 1; i++)
    {
        cout << t[i][0] << "--" << t[i][1] << endl;
    }
}
int main()
{
    graph g;
    g.getgraph();
    g.prim();
    return 0;
}
