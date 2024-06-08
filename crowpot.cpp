#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


//question with -1 in the begining of the stones array. we sort that array
//let x be the max(N, tot_stones);
//dp array of (x+2)*(x+2) initialized to INT_MAX

// dp[i][1] initialization dp[i][1]=stones[i]*(N-i+1)
//three for loops
/////i from N to 1 (i--)
/////////j from 2 to tot_stones (j++)
////////////k from i+1 to N (k++)
//////////// dp[i][j]=min(dp[i][j], d[k][j-1]+(k-i)*stones[i])


//to find the ans we find the minimum in dp[i][tot_stones]

int main(){
    int N, tot_stones;
    cin>>N>>tot_stones;
    vector<int> stones(N+1, -1);
    for(int i=1; i<=N; i++) cin>>stones[i];
    sort(stones.begin(), stones.end());
    int x = max(N ,tot_stones);
    vector<vector<int> > dp(x+2, vector<int>(x+2, INT_MAX));
    for(int i=1; i<=N; i++) dp[i][1]=stones[i]*(N-i+1);
    for(int i=N ; i<=1; i--){
        for(int j=2; j<=tot_stones; j++){
            for(int k=i+1; k<=N; k++){
                dp[i][j]=min(dp[i][j], dp[k][j-1]+(k-i)*stones[i]);
            }
        }
    }
    int ans = INT_MAX;
    for(int i=1; i<=N; i++) ans=min(ans, dp[i][tot_stones]);
    cout<<ans<<endl;

}