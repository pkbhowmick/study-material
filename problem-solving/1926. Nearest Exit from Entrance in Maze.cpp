class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};

    bool valid(int i, int j, int n, int m){
        if(i<0 || j<0){
            return false;
        }
        if(i>=n || j>=m){
            return false;
        }
        return true;
    }

    int isborder(int i, int j, int n, int m){
        if (i==0 || j==0 || i == n-1 || j == m-1)
            return true;
        return false;
    }

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        queue<int>q;
        q.push(entrance[0]);
        q.push(entrance[1]);
        int n = maze.size();
        int m = maze[0].size();
        int vis[101][101];
        memset(vis, -1, sizeof vis);
        vis[entrance[0]][entrance[1]] = 0;

        int ans = 10001;

        while(!q.empty()){
            int x = q.front();
            q.pop();
            int y = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int xx= x+dx[i];
                int yy= y+dy[i];

                if(valid(xx,yy,n,m) && vis[xx][yy] == -1 && maze[xx][yy] == '.'){
                    vis[xx][yy] = vis[x][y] + 1;
                    q.push(xx);
                    q.push(yy);

                    if(isborder(xx,yy,n,m)){
                        ans = min(ans,vis[xx][yy]);
                    }
                }
            }
        }
        if(ans == 10001)
            ans = -1;
        return ans;
    }
};
