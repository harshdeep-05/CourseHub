class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0,n = start.size();
    while(n>i && n>j){
        
        while(start[i] == '_')
            i++;
        
        while(target[j] == '_') j++;
        
        if(target[j] != start[i]) return false; 
        
        if(start[i] == 'R'){
            if(i>j)return false;
        }
        else if(start[i] == 'L'){
            if(j>i)return false;
        }
        i++;j++;    
    }
    return true;
    }
};