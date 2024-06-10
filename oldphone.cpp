#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, o, target;
int ans = INT_MAX;

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m>>o;
        ans = INT_MAX;
        int allowed_nos[n];
        int allowed_op[m];
        queue<pair<int, int> > q;
        for(int i=0; i<n; i++){
            cin>>allowed_nos[i];
            q.push(make_pair(allowed_nos[i], 1));
        }
        for(int i=0; i<m; i++){
            cin>>allowed_op[i];
        }
        unordered_map<int, int> allowed_op_map;
        for(int i=0; i<m; i++){
            allowed_op_map[allowed_op[i]]=1;
        }
        cin>>target;
        while(!q.empty()){
            int curr_number = q.front().first;
            int no_of_op = q.front().second;
            if(curr_number==target){
                ans=min(ans, no_of_op);
            }
            q.pop();
            for(int i=0; i<=4; i++){
                for(int j=0; j<n; j++){
                    if(i==0 && no_of_op+1<=o){
                        q.push(make_pair(curr_number*10+allowed_nos[j], no_of_op+1));
                    }
                    else{
                         if(i==1 && allowed_op_map.find(i)!=allowed_op_map.end() && no_of_op+3<=o){
                            q.push(make_pair(curr_number+allowed_nos[j], no_of_op+3));
                         }
                         if(i==2 && allowed_op_map.find(i)!=allowed_op_map.end() && no_of_op+3<=o){
                            q.push(make_pair(abs(curr_number-allowed_nos[j]), no_of_op+3));
                         }
                         if(i==3 && allowed_op_map.find(i)!=allowed_op_map.end() && no_of_op+3<=o){
                            q.push(make_pair(curr_number*allowed_nos[j], no_of_op+3));
                         }
                         if(i==4 && allowed_op_map.find(i)!=allowed_op_map.end() && no_of_op+3<=o ){
                            q.push(make_pair(curr_number/allowed_nos[j], no_of_op+3));
                         }
                        //  else if(i==4 && allowed_op_map.find(i)!=allowed_op_map.end() && no_of_op+3<=o && allowed_nos[i]!=0 && curr_number>allowed_nos[j]){
                        //     q.push(make_pair(curr_number/allowed_nos[j], no_of_op+3));
                        //  }
                        //  else if(i==4 && allowed_op_map.find(i)!=allowed_op_map.end() && no_of_op+3<=o && curr_number!=0 && curr_number<allowed_nos[j]){
                        //     q.push(make_pair(allowed_nos[j]/curr_number, no_of_op+3));
                        //  }
                    }
                }
            }
        }
        if(ans==INT_MAX){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    allowed_op_map.clear();
    }
}