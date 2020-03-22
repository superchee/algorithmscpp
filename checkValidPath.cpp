#include <vector>

using namespace std;


class Solution {
public:
    int n, m;
    vector<vector<int>> g;
    int di[4]={1, -1, 0, 0}, dj[4]={0, 0, 1, -1}, t[6]={4|8, 1|2, 8|1, 4|1, 8|2, 4|2};
    vector<vector<bool>> vis;
    bool dfs(int i, int j) {
        if(i==n-1&&j==m-1)
            return 1;
        vis[i][j]=1;
        for(int k=0; k<4; ++k) {
            if(t[g[i][j]-1]>>k&1^1)
                continue;
            int ni=i+di[k], nj=j+dj[k];
            if(ni<0||ni>=n||nj<0||nj>=m||vis[ni][nj])
                continue;
            int k2=k^1;
            if(t[g[ni][nj]-1]>>k2&1^1)
                continue;
            if(dfs(ni, nj))
                return 1;
        }
        return 0;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        g=grid;
        vis = vector<vector<bool>>(n, vector<bool>(m));
        return dfs(0, 0);
    }
};