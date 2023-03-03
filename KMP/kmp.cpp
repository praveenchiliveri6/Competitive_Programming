
// find whether needle is present as a substring in haystack or not
// if present return the index of the needle string in haystack else return -1
// 1<=str len<=10000

class Solution {
public:

    vector<int> constructLPSArray(string &s){
        int i=1,len=0,n=s.length();
        vector<int> lps(n,0);
        while(i<n){
            if(s[i]==s[len]){
                lps[i]=len+1;
                i++;
                len++;
            }
            else if(len>0){
                len=lps[len-1];
            }
            else{
                i++;
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        vector<int> lps=constructLPSArray(needle);
        int n1=haystack.length(),n2=needle.length(),i=0,j=0;
        while(i<n1){
            if(haystack[i]==needle[j]){
                i++;
                j++;

                if(j==n2)
                    return i-j;
            }
            else{
                if(j>0)
                    j=lps[j-1];
                else
                    i++;
            }

        }

        return -1;
    }
};
