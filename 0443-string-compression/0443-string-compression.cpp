class Solution {
public:
    int compress(vector<char>& chars) {
        int idx=0,i,n=chars.size(),count=0;
        char ch;
        string digits;
        for(i=0;i<n;){
            ch=chars[i];
            count=0;
            while(i<n && chars[i]==ch)
            {
                count+=1;
                i+=1;
            }
            if(count==1)
            {
                chars[idx++]=ch;
            }
            else{
                chars[idx++]=ch;
                digits=to_string(count);
                for(char digit:digits)
                {
                    chars[idx++]=digit;
                }
            }
        }
        chars.resize(idx);
        return idx;
    }
};