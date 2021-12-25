class Solution {
public:
    
    bool check(string& a, string& b){
        int diff=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])
               diff++;
        }
        return diff==1;
        
    }
    
    
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
         
        unordered_map<string,vector<string>> adj;
        
        for(int i=0;i<wordList.size();i++){
            for(int j=0;j<wordList.size();j++){
                if(check(wordList[i],wordList[j])) adj[wordList[i]].push_back(wordList[j]);
             }
        }
        
        unordered_map<string,bool> vis;        
        queue<string> q;
        q.push(beginWord);
        vis[beginWord]=1;
        
        int ans=1;
        
        while(!q.empty()){
            
            int t=q.size();
              while(t--){
                  string a=q.front(); q.pop();
                  for(string b:adj[a]){
                    if(b==endWord) return ans+1;
                      if(vis.find(b)==vis.end()){
                         q.push(b);
                         vis[b]=1;
                      }
                      
                  }
               }
            ans++;
        }
        
        return 0;
          
    }
};