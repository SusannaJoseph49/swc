#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int bfs(int sx, int sy, int rare_ele_x, int rare_ele_y, vector<vector<int> >&grid) {
    int n = grid.size();
    vector<vector<int> > vis(n, vector<int>(n, 0));
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(sx, sy), 0));
    vis[sx][sy] = 1;
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int level = q.front().second;
        q.pop();
        
        if (x == rare_ele_x && y == rare_ele_y) {
            return level;
        }
        
        for (int i = 0; i < 4; i++) {
            int newx = x + dx[i];
            int newy = y + dy[i];
            int newlevel = level + 1;
            
            if (newx >= 0 && newx < n && newy >= 0 && newy < n) {
                if (grid[newx][newy] == 1 && vis[newx][newy] == 0) {
                    q.push(make_pair(make_pair(newx, newy), newlevel));
                    vis[newx][newy] = 1;
                }
            }
        }
    }
    return INT_MIN; 
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, no_of_elements;
        cin >> n >> no_of_elements;
        
        vector<pair<int, int> > rare_elements(no_of_elements);  
        for (int i = 0; i < no_of_elements; i++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            rare_elements[i] = make_pair(x, y);
        }
        
        vector<vector<int> > grid(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }
        
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int temp = 0;
                    for (int k = 0; k < no_of_elements; k++) {
                        int res = bfs(i, j, rare_elements[k].first, rare_elements[k].second, grid);
                        temp = max(res, temp);
                    }
                    ans = min(ans, temp);
                }
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
