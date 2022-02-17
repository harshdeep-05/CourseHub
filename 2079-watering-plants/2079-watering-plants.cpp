class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans=0,n=plants.size(),bucket=capacity;
        for(int i=0;i<n;i++)
        {
            if(bucket>=plants[i])
            {
                ans++;
                bucket-=plants[i];
            }
            else 
            {
                ans+=2*i+1;
                bucket=capacity-plants[i];
            }
        }
        return ans;
    }
};