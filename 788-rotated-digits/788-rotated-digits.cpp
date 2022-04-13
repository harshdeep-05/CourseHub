class Solution {
public:
    int rotatedDigits(int n) {
        int ans=0;
        vector<int> rot={1,1,2,0,0,2,2,0,1,2};
        for(int i=1;i<=n;i++)
        {
            int num=i,s=1;
            while(num)
            {
                s*=rot[num%10];
                num/=10;
            }
            if(s>=2)ans++;
        }
        return ans;
    }
};