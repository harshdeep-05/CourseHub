class Solution {
public:
    string largestOddNumber(string num) {
        int n=num.size();
        string ans;
        for(int i=n-1;i>=0;i--)
        {
            int x=num[i]-'0';
            if(x%2)
            {
                ans=num.substr(0,i+1);
                return ans;
            }
        }
        return "";
    }
};