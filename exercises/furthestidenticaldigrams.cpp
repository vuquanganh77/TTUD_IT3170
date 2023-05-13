#include<bits/stdc++.h>

using namespace std;

int main()
{
    //Find the distance between the furthest identical diagrams inside String S
    string s;
    cin>>s;
    int n=s.length();
    int max=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(s[i]==s[j])
            {
                if(j-i>max)
                {
                    max=j-i;
                }
            }
        }
    }
    cout<<max;
    return 0;
}
