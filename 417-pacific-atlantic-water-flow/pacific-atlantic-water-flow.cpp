class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        int n=heights.size();
        int m=heights[0].size();
        queue<pair<int,int>>pac; //store bfs of pacific ocean
        queue<pair<int,int>>at; //store bfs of atlantic ocean
        vector<vector<bool>>pacific(n,vector<bool>(m,0)); //store infected cells by pacific waters
        vector<vector<bool>>atlantic(n,vector<bool>(m,0)); //store infected cells by atlantic waters
        for(int i=0;i<n;i++){
            pac.push({i,0}); //full 1st column in pacific 
            pacific[i][0]=1; //mark the sources as infected
            at.push({i,m-1}); //full last column in atlantic
            atlantic[i][m-1]=1; //mark the sources as infected
        }
        for(int j=1;j<m;j++){
            pacific[0][j]=1;
            pac.push({0,j}); //first row except 1st corner cell (duplicate)
        }
        for(int j=0;j<m-1;j++){
            at.push({n-1,j}); //last row except last corner cell (already pushed)
            atlantic[n-1][j]=1;
        }
        //for pacific ocean
        while(pac.size()){
            auto curr=pac.front();
            pac.pop();
            int row=curr.first;
            int col=curr.second;
            int val=heights[row][col];
            for(int i=0;i<4;i++){
                int r=row+dir[i].first;
                int c=col+dir[i].second; 
                //move ahead for out of grid/already visited/value<current value
                if(r<0||c<0||r>n-1||c>m-1||pacific[r][c]==1||heights[r][c]<val)continue; 
                else{
                    pacific[r][c]=1;
                    pac.push({r,c});
                }
            }
        }
        //atlantic ocean
        while(at.size()){
            auto curr=at.front();
            at.pop();
            int row=curr.first;
            int col=curr.second;
            int val=heights[row][col];
            for(int i=0;i<4;i++){
                int r=row+dir[i].first;
                int c=col+dir[i].second;
                if(r<0||c<0||r>n-1||c>m-1||atlantic[r][c]==1||heights[r][c]<val)continue; 
                else{
                    at.push({r,c});
                    atlantic[r][c]=1;
                }
            }
        }
        //final traverse and push cells infected by both waters
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j]==1&&atlantic[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};