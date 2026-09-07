#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long matrixChainMultiplication(const vector<int>& p) {
    int n = p.size() - 1;   // Number of matrices

    vector<vector<long long>> dp(n + 1,
                                 vector<long long>(n + 1, 0));

    // len = number of matrices in the current chain
    for (int len = 2; len <= n; len++) {

        for (int i = 1; i <= n - len + 1; i++) {

            int j = i + len - 1;
            dp[i][j] = LLONG_MAX;

            // Try every possible splitting point
            for (int k = i; k < j; k++) {

                long long cost =
                    dp[i][k] +
                    dp[k + 1][j] +
                    1LL * p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main() {
    // A1 = 40x20
    // A2 = 20x30
    // A3 = 30x10
    // A4 = 10x30
    vector<int> dimensions = {40, 20, 30, 10, 30};

    cout << "Minimum number of multiplications: "
         << matrixChainMultiplication(dimensions)
         << endl;

    return 0;
}