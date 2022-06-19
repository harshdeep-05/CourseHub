class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        int n=products.size(),m=searchWord.size();
        int l=0,r=n-1;
        
        vector<vector<string>> ans(m);
        for(int i=0;i<m;i++)
        {
            while(l<=r && (products[l].size()<=i || products[l][i]!=searchWord[i]))
            {
                l++;
            }
            while(l<=r && (products[r].size()<=i || products[r][i]!=searchWord[i]))
            {
                r--;
            }
            
            for(int k=l;k<=min(r,l+2);k++)ans[i].push_back(products[k]);
        }
        return ans;
    }
};