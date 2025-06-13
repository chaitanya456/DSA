#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n,int target);
int main()
{
    vector<int>a={15,2,4,8,9,5,10,23};
    int n=a.size();
    int target=23;
    func(a,n,target);
    return 0;
}
void func(vector<int>&a, int n,int target)
{
    int i;
    int windowStart=0,windowEnd=0;
    int currSum=0;
    for(i=0;i<n;i++)
    {
        currSum+=a[i];
        if(currSum>=target)
        {
            windowEnd=i;
            while(currSum>target && windowStart<windowEnd)
            {
                currSum-=a[windowStart];
                windowStart++;
            }
            if(currSum==target)
            {
                cout<<"Found between indices: "<<windowStart<<","<<windowEnd<<endl;
                break;
            }
        }
    }
}