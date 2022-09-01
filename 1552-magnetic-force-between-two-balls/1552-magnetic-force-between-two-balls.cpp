class Solution {
public:
    bool possible(vector<int>& position,int m,int &min_dist)
    {
        int last=0,n=position.size(),i=1;
        m--;
        while(m && i<n)
        {
            if(position[i]-position[last]<min_dist)
            {
                i++;
                continue;
            }
            else
            {
                last=i;
                m--;
            }
        }
        return (m==0);
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int low=1,high=position[n-1]-position[0]+1;
        int ans;
        while(low<high)
        {
            int min_dist=low+(high-low)/2;
            if(possible(position,m,min_dist))
            {
                ans=min_dist;
                low=min_dist+1;
            }
            else high=min_dist;
        }
        return ans;
    }
};