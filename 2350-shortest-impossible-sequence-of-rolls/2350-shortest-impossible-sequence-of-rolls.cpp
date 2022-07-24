class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int size=1;
        set<int> s;
        for(int i=0;i<rolls.size();i++)
        {
            s.insert(rolls[i]);
            if(s.size()==k)
            {
                size++;
                s.clear();
            }
        }
            return size;
    }
};