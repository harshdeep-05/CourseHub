class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size(),cur=1;
        int ans=0,j=n-1,i=0;
        while(i<j)
        {
            if(height[i]<height[j])
            {
                cur=height[i]*(j-i);
                i++;
            }
            else
            {
                cur=height[j]*(j-i);
                j--;
            }
            ans=max(ans,cur);
            
        }
        return ans;
    }
};