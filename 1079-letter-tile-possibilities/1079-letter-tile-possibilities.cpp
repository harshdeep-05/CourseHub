class Solution {
public:
    void solve(string tiles,int i,int &ans)
    {
        ans++;
        for(int j=i;j<tiles.size();j++)
        {
            if(j!=i && tiles[i]==tiles[j])continue;
            
            swap(tiles[i],tiles[j]);
            solve(tiles,i+1,ans);
        }
        
    }
    int numTilePossibilities(string tiles) {
        int ans=0;
        sort(tiles.begin(), tiles.end()); 
        solve(tiles,0,ans);
        return ans-1;
    }
};