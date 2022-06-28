class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string s="";
        for(auto i:board)
        {
            for(int j=0;j<i.size();j++)s+=to_string(i[j]);
        }
        string target="123450";
        
        unordered_map<int,vector<int>> dir;
        dir[0]={1,3};
        dir[1]={0,2,4};
        dir[2]={1,5};
        dir[3]={0,4};
        dir[4]={1,3,5};
        dir[5]={2,4};
        
        queue<string> q;
        unordered_map<string,bool> vis;
        q.push(s);
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
                auto cur=q.front();
                q.pop();
                if(cur==target)
                {
                    return ans;
                }
                int pos;
                for(int i=0;i<6;i++)
                {
                    if(cur[i]=='0')pos=i;
                }
                for(auto i:dir[pos])
                {
                    string temp=cur;
                    swap(temp[i],temp[pos]);
                    if(vis[temp]==true)continue;
                    q.push(temp);
                    vis[temp]=true;
                }
                
            }
            ans++;
        }
        return -1;
            
    }
};