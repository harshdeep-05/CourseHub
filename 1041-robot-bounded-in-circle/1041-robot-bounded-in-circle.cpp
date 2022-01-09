class Solution {
public:
    bool isRobotBounded(string instructions) {
        int x=0,y=0,dir=0;
        
        for(auto i:instructions)
        {
            if(i=='G')
            {
                if(dir==0)x++;
                else if(dir==1)y++;
                else if(dir==2)x--;
                else y--;
            }
            else if(i=='L')
            {
                if(dir==0)dir=3;
                else dir--;
            }
            if(i=='R')
            {
                if(dir==3)dir=0;
                else dir++;
            }
            
        }
        return((x==0 && y==0)  || dir!=0);
    }
};