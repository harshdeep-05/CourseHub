class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        vector<int> one;
        for(int i=0;i<seats.size();i++)
        {
            if(seats[i]==1)one.push_back(i);
        }
        int s=one.size(),n=seats.size();
        int index=0,max_dist=one[0];
        for(int i=1;i<one.size();i++)
        {
            int closest_dist=(one[i]-one[i-1])/2;
            if(closest_dist>max_dist)
            {
                max_dist=closest_dist;
                index=(one[i]+one[i-1])/2;
            }
        }
        
        if(max_dist<n-one[s-1]){
            max_dist=n-one[s-1]-1;
            index=n;
        }
        cout<<index<<" ";
        return max_dist;
    }
};