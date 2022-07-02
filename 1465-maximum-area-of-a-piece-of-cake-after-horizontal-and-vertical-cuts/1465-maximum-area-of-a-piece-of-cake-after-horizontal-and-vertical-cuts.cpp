class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        sort(begin(hc),end(hc));
        sort(begin(vc),end(vc));
        const int mod=1e9+7;
        int hz=max(hc[0],h-hc.back()),vt=max(vc[0],w-vc.back());
        for(int i=1;i<hc.size();i++)
        {
            hz=max(hz,hc[i]-hc[i-1]);
        }
        for(int i=1;i<vc.size();i++)
        {
            vt=max(vt,vc[i]-vc[i-1]);
        }
        return ((long long)hz*vt)%mod;
    }
};