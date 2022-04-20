class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s=num;
        while(k--)
        {
            next_permutation(num.begin(),num.end());
        }
        
        int ans=0,i=0,j=0;
        while(i<num.size())
        {
            j=i;
            while(s[j]!=num[i])j++;
            
            while(i<j)
            {
                swap(s[j],s[j-1]);
                ans++;
                j--;
            }
            i++;
        }
        return ans;
    }
};