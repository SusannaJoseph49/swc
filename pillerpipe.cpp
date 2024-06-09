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
//solve function take vector<int>&bricks, int index, int piller1, int piller2
//if index==n and piller1==piller 2 =>>>>return piller1
int solve(vector<int>&bricks, int index, int piller1 , int piller2){
    if(index==bricks.size()){
        if(piller1==piller2){
            return piller1;
        }
        return 0;
    }
    int ans = INT_MIN;
    int take_to_piller1 = max(ans, solve(bricks, index+1, piller1+bricks[index], piller2));
    int take_to_piller2 = max(ans, solve(bricks, index+1, piller1, piller2+bricks[index]));
    int do_not_take = max(ans, solve(bricks, index+1, piller1, piller2));

    return max(max(take_to_piller1, take_to_piller2),do_not_take);
}
int main(){
    int T; cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> bricks(n, 0);
        for(int i=0; i<n; i++){
            cin>>bricks[i];
        }
        cout<<solve(bricks, 0, 0, 0)<<endl;
    }
}