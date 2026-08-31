#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int knapsack(int W, vector<int>& weight, vector<int>& value, int n) {
    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {

            // If current item can fit
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    value[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
            else {
                // Cannot include the item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weight(n);
    vector<int> value(n);

    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++) {
        cin >> value[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maximumValue = knapsack(W, weight, value, n);

    cout << "Maximum value = " << maximumValue << endl;

    return 0;
}
