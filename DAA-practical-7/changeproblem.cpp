#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minCoins(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);

    // Base case
    dp[0] = 0;

    // Calculate minimum coins for every amount
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (coin <= i && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If amount cannot be formed
    if (dp[amount] == INT_MAX)
        return -1;

    return dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int result = minCoins(coins, amount);

    if (result == -1)
        cout << "Change cannot be made." << endl;
    else
        cout << "Minimum number of coins required: "
             << result << endl;

    return 0;
}