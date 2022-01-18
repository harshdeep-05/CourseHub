class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m=flowerbed.size();
        if(m==1 && n<=1 && flowerbed[0]==0)return true;
        if(flowerbed[0]==0 && flowerbed[1]!=1)
            {
                flowerbed[0]=1;
                n--;
            }
        if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]!=1)
            {
                flowerbed[flowerbed.size()-1]=1;
                n--;
            }
        
        for(int i=1;i<flowerbed.size()-1;i++)
        {
            if(flowerbed[i]==0 && (flowerbed[i-1]!=1 && flowerbed[i+1]!=1))
            {
                flowerbed[i]=1;
                n--;
            }
        }
        return (n<=0);
    }
};