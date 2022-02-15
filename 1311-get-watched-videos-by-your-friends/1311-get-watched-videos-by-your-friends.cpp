class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n=friends.size();
        unordered_map<string,int> m;
        vector<bool> vis(n,0);
        queue<int> q;
        q.push(id);
        vis[id]=1;
        int l=-1;
        while(!q.empty())
        {
            l++;
            int s=q.size();
            while(s--)
            {
                int top=q.front();
                q.pop();
                
                if(l==level){
                    for(auto x:watchedVideos[top])m[x]++;
                }
                
                for(auto j:friends[top])
                {
                    if(!vis[j]){
                        q.push(j);
                        vis[j]=1;
                    }
                }
            }
        }
        
        vector<string> ans;
        set<pair<int,string>> a;
        for(auto x:m)
        {
            a.insert({x.second,x.first});
        }
        for(auto s:a)ans.push_back(s.second);
        
        return ans;
    }
};