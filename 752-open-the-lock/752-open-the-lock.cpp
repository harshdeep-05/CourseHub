class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        if(target=="0000")return 0;
        queue<string> q;
        q.push("0000");
        
        unordered_map<string,int> m;
        for(auto s:deadends)m[s]=1;
        int moves=0;
        while(!q.empty())
        {
            int s=q.size();
            moves++;
            while(s--)
            {
                auto top=q.front();
                q.pop();
                
                if(top==target)return moves-1;
                if(m.find(top)!=m.end())continue;
                m[top]=1;
                
                for(int i=0;i<4;i++)
                {
                    string temp = top;
                    int a = temp[i] - '0' + 1;
                    int b = temp[i] - '0' - 1;
                    
                    if(b < 0) b += 10;
                    a = a%10, b = b%10;
                    
                    temp[i] = a + '0';
                    q.push(temp);
                    temp[i] = b + '0';
                    q.push(temp);
                }
            }
        }
        return -1;
    }
};