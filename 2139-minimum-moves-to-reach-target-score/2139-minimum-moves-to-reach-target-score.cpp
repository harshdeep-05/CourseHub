class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans=0;
        while(target>1)
        {
            if(maxDoubles==0)
            {
                ans+=target-1;
                target=1;
            }
            else if(target%2){
                target--;
                ans++;
            }
            else {
                target/=2;
                maxDoubles--;
                ans++;
            }
        }
        return ans;
    }
};