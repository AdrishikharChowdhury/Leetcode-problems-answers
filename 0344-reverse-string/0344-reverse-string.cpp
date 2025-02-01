class Solution {
public:
    void reverseString(vector<char>& s) {
        int i,n=s.size();
        for(i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
    }
};