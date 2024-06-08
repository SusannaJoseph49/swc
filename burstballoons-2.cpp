#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//append 1 to the start and begining of the coins array and make it of a size N+2

//dp question (dp array of N+2 x N+2)

//three for loops
////// i from N to 1 (i--)
///////// j from i to N (j++)
////////  initialize a maxi varible to INT_MIN
///////////// k form i to j  (k++)
//////////// compute cost
//////////// maxi=max(maxi, cost)
//////// dp[i][j]=maxi


// return dp[1][n]


int main(){
    int N;
    cin>>N;
    vector<int> coins;
    coins.push_back(1);
    for(int i=0; i<N; i++){
        int x; cin>>x;
        coins.push_back(x);
    }
    coins.push_back(1);
    vector<vector<int> > dp(N+2, vector<int>(N+2,0));
    for(int i=N; i>=1; i--){
        for(int j= i; j<=N; j++){
            int maxi = INT_MIN;
            for(int k=i; k<=j; k++){
                int cost = coins[i-1]*coins[k]*coins[j+1] + dp[i][k-1] + dp[k+1][j];
                maxi=max(maxi, cost);
            }
            dp[i][j]=maxi;
        }
    }
    cout<<dp[1][N]<<endl;
}