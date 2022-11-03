//
// Created by Lanture on 2022/11/3.
//
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<bool> > visited;
    vector<vector<int> > dis = {{-1,0},{1,0},{0,-1},{0,1}};
    int n, m;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.assign(n, vector<bool> (m,false));
        int res = 0;
        for( int i=0; i<n; i++){
            for( int j=0; j<m; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    dfs(grid,i,j);
                    res++;
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!='1'){
            return;
        }
        grid[i][j] = '2';
        visited[i][j] = true;
        for(int k=0;k<dis.size();k++){
            dfs(grid,i+dis[k][0],j+dis[k][1]);
        }
    }
};
