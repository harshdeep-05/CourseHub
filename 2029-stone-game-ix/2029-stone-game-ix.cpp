class Solution {
public:
    bool solve(int sum,int a,int b,int c,int n)
    {
        for(int i=1;i<n;i++)
        {
            if(i%2==0) //optimal for alice
            {
                bool flag=0;
                optimal(a,b,c,sum,flag);
                if(flag)return 0;
            }
            else //optimal for bob
            {
                bool flag=0;
                optimal(a,b,c,sum,flag);
                if(flag)return 1;
            }
        }
        return 0;
    }
    void optimal(int &a,int &b,int &c,int &sum,bool &flag)
    {
    
        if(sum==1)
        {
            if(!a && !c){
                flag=1;
                return ;
            }
            else 
            {
                if(a)sum=2,a--;
                else c--;
            }
        }
        else if(sum==2)
        {
            if(!b && !c){
                flag=1;
                return; 
            }
            else
            {
                if(b)sum=1,b--;
                else c--;
            }
        }
    }
    bool stoneGameIX(vector<int>& stones) {
        int a=0,b=0,c=0;
        for(auto i:stones)
        {
            if(i%3==1)a++;
            else if(i%3==2)b++;
            else c++;
        }
        if(a && b)
        {
            return solve(1,a-1,b,c,stones.size())||solve(2,a,b-1,c,stones.size());
        }
        else if(a)
        {
            return solve(1,a-1,b,c,stones.size());
        }
        return solve(2,a,b-1,c,stones.size());
        
        
    }
};