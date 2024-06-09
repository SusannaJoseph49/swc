#include <iostream>
#include <cmath>
#include <vector>
#include <limits.h>
#include <algorithm>

using namespace std;

int N, gatePos1, gatePos2, gatePos3;

int calculateHash(int a, int b, int c) {
    return 10000 * a + 100 * b + c;
}

int minCost(int pos, int fisher1, int fisher2, int fisher3, vector<vector<int> > &dp) {
    if (fisher1 < 0 || fisher2 < 0 || fisher3 < 0) {
        return INT_MAX / 2;
    }
    if (pos > N) {
        if (fisher1 == 0 && fisher2 == 0 && fisher3 == 0) return 0;
        else return INT_MAX / 2;
    }
    int Hashindex = calculateHash(fisher1, fisher2, fisher3);
    if (dp[pos][Hashindex] != -1) {
        return dp[pos][Hashindex];
    }
    int takefisher1 = 1 + abs(pos - gatePos1) + minCost(pos + 1, fisher1 - 1, fisher2, fisher3, dp);
    int takefisher2 = 1 + abs(pos - gatePos2) + minCost(pos + 1, fisher1, fisher2 - 1, fisher3, dp);
    int takefisher3 = 1 + abs(pos - gatePos3) + minCost(pos + 1, fisher1, fisher2, fisher3 - 1, dp);
    int takenone = minCost(pos + 1, fisher1, fisher2, fisher3, dp);

    dp[pos][Hashindex] = min(min(takefisher1, takefisher2), min(takefisher3, takenone));
    return dp[pos][Hashindex];
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int fisher1, fisher2, fisher3;
        cin >> N;
        cin >> gatePos1 >> gatePos2 >> gatePos3;
        cin >> fisher1 >> fisher2 >> fisher3;

        // Reset the dp table
        vector<vector<int> > dp(N+1, vector<int>(1000005, -1));

        cout << minCost(1, fisher1, fisher2, fisher3, dp) << endl;
    }
    return 0;
}
