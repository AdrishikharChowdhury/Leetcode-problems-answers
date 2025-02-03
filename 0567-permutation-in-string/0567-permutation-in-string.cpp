class Solution {
public:
    bool isFreqSame(int a[],int b[])
    {
        for(int i=0;i<26;i++)
        {
            if(a[i]!=b[i])
            {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int i,freq[26]={0};
        for(i=0;i<s1.length();i++)
        {
            freq[s1[i]-'a']+=1;
        }
        int windSize=s1.length();
        for(i=0;i<s2.length();i++)
        {
            int windIdx=0,idx=i;
            int windFreq[26]={0};
            while(windIdx<windSize && idx<s2.length())
            {
                windFreq[s2[idx]-'a']+=1;
                windIdx+=1;
                idx+=1;
            }
            if(isFreqSame(freq,windFreq)){
                return true;
            }
        }
        return false;
    }
};