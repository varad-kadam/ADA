#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int knapSack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}

int main() {
    int n, weight[100], profit[100] = {60, 100, 120}, W, i;

    cout << "enter max size:";
    cin >> n;

    cout << "Enter profit";
    for (i = 0; i < n; i++) {
        cin >> profit[i];
    }

    cout << "Enter weights associated";
    for (i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter max capacity:";
    cin >> W;

    cout << knapSack(W, weight, profit, n);
    return 0;
}
