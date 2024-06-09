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

int main(){
    int T; cin>>T;
    while(T--){
        int start, end, n, k;
        cin>>n>>start>>end>>k;
        set<int> s;
        for(int i=0; i<n; i++){
            int x; cin>>x;
            s.insert(x);
        }
        int ans = 0;
        for(int i=start; i<=end; i++){
            int currno = i;
            int bad_digits = 0;
            while(currno>0){
                int currdig = currno%10;
                if(s.find(currdig)!=s.end()){
                    bad_digits++;
                }
                currno=currno/10;
            }
            if(bad_digits>=k){
                  ans++;
            }
        }
        cout<<ans<<endl;
    }
}