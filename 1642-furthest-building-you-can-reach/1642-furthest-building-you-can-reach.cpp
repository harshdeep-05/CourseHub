class Solution {
public:
    /*
    int solve(vector<int>& h, int bricks, int ladders,int i)
    {
        if(i==h.size())return 0;
        
        if(h[i]<=h[i-1])return solve(h,bricks,ladders,i+1)+1;
        if((bricks==0 && ladders==0))return 0;
        int a=0,b=0;
        if(bricks>=h[i]-h[i-1])
            a=solve(h,bricks-(h[i]-h[i-1]),ladders,i+1)+1;
        if(ladders>0)
            b=solve(h,bricks,ladders-1,i+1)+1;
        return max(a,b);
         
    }
    */
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        int n=h.size();
        priority_queue<int,vector<int>,greater<int>> q;
        
        for(int i=0;i<n-1;i++)
        {
            if(h[i+1]<=h[i])continue;
            
            int x=h[i+1]-h[i];
            q.push(x);
            if(q.size()>ladders)
            {
                bricks-=q.top();
                q.pop();
                
            }
            if(bricks<0)return i;
        }
        return n-1;
    }
};