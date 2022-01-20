class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        //sort(piles.begin(),piles.end());
        int l=1,r=*max_element(piles.begin(),piles.end());
        while(l<r)
        {
            int m=l+(r-l)/2,time=0;
            for(int i:piles)time+=i/m+(i%m!=0);
            
            if(time<=h)r=m;
            else l=m+1;
        }
        return r;

        
    }
};