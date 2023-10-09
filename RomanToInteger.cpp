class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mpp;
        mpp['I']=1;
        mpp['V']=5;
        mpp['X']=10;
        mpp['L']=50;
        mpp['C']=100;
        mpp['D']=500;
        mpp['M']=1000;

        int ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='I' && i<s.size()-1){
                if(s[i+1]=='V' || s[i+1]=='X'){
                    ans=ans-1;
                }
                else {
                    ans=ans+1;
                }
            }
            else if(s[i]=='X' && i<s.size()-1){
                if(s[i+1]=='L' || s[i+1]=='C'){
                    ans=ans-10;
                }
                else {
                    ans=ans+10;
                }
            }
            else if(s[i]=='C' && i<s.size()-1){
                if(s[i+1]=='D' || s[i+1]=='M'){
                    ans=ans-100;
                }
                else {
                    ans=ans+100;
                }
            }
            else{
                ans=ans+mpp[s[i]];
            }

        }
        return ans;
    }
};
