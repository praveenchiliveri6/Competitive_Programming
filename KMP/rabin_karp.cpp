/*
Given two strings, one is a text string, txt and other is a pattern string, pat. 
The task is to print the indexes of all the occurences of pattern string in the text string. 
Use one-based indexing while returning the indices. 
Note: Return an empty list incase of no occurences of pattern.
*/

vector <int> search(string pat, string txt)
{
    vector<int> foundIndexes;
    int n=pat.size(),mod=1e9+7;
    long long base=1,patternHash=0,maxBase=1;
    // pattern length is m and txt length is n
    // pattern hash = (26^m-1 *pat[0]+....26^0 * pat[m-1])
    for(int i=n-1;i>=0;i--,base=(base*26)%mod){
        patternHash=(patternHash+(base*(pat[i]-'a'+1))%mod)%mod;
    }

    // calculate maxBase=(26^m-1) to subtract when we move the window by one step.
    for(int i=1;i<n;i++){
        maxBase=(maxBase*26)%mod;
    }
    
    long long txtHash=0;
    int m=txt.length();
    for(int i=0;i<m;i++){
        // subtract the first character hash from current window
        if(i>=n){
            txtHash=(txtHash-(maxBase*(txt[i-n]-'a'+1))%mod+mod)%mod;
        }
        // when we move the window by one step, hash will be multiplied by 26
        txtHash=(txtHash*26)%mod;
        txtHash=(txtHash+(txt[i]-'a'+1))%mod;

        // hashes match and push the beginning of the window index(1-indexing)
        if(i>=n-1 and txtHash==patternHash){
            foundIndexes.push_back(i-n+2);
        }
    }
    
    return foundIndexes;
}
