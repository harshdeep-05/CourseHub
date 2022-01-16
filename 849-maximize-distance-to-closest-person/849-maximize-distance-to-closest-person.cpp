class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size(),l=0,max_dist=0;
        
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)l=0;
            else
            {
                l++;
                max_dist=max(max_dist,(l+1)/2);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(seats[i]==1)
            {
                max_dist=max(max_dist,i);
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(seats[n-i-1]==1)
            {
                max_dist=max(max_dist,i);
                break;
            }
        }
        return max_dist;
    }
};