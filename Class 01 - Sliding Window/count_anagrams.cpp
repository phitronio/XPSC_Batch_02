#include<bits/stdc++.h>
using namespace std;
int main()
{
    string txt,ptr;
    cin>>txt>>ptr;
    int k=ptr.size(),i=0,j=0;
    int fr1[26]={0};
    int fr2[26]={0};
    for(char c:ptr)
    {
        fr1[c-'a']++;
    }
    int ans=0;
    while(j<txt.size())
    {
        fr2[txt[j]-'a']++;
        if(j<k-1)
        {
            j++;
        }
        else 
        {
            bool flag=true;
            for(int v=0;v<26;v++)
            {
                if(fr1[v] != fr2[v])
                {
                    flag=false;
                    break;
                }
            }
            if(flag) ans++;
            fr2[txt[i]-'a']--;
            i++;
            j++;
        }
    }
    cout<<ans<<endl;
    return 0;
}