class Solution {
public:
    int maximum69Number (int num) {
        int rev=0,flag=1;
        while(num)
        {
            rev=rev*10+num%10;
            num/=10;
        }
        num=0;
        while(rev)
        {
            if(flag && rev%10==6)
            {
                num=num*10+9;
                flag=0;
            }
            else num=num*10+rev%10;
            rev/=10;
        }
        return num;
    }
};