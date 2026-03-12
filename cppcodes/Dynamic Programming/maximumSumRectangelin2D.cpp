#include<bits/stdc++.h>
using namespace std;
int kadane(vector<int>&nums)
{
    int i;
    int n=nums.size();
    int max_so_far=nums[0],res=nums[0];
    for(i=1;i<n;i++)
    {
        max_so_far=max(max_so_far+nums[i],nums[i]);
        res=max(max_so_far,res);
    }
    return res;
}
int maxRectSum(vector<vector<int>> &a) 
{
    int m=a.size();
    int n=a[0].size();
    int left,right;
    int res=INT_MIN;
    for(left=0;left<n;left++)
    {
        vector<int>temp(m,0);
        for(right=left;right<n;right++)
        {
            for(int k=0;k<m;k++)
            temp[k]+=a[k][right];
            int sum=kadane(temp);
            res=max(sum,res);
        }
    }
    return res;
    
}

int main()
{
    vector<vector<int>>a={  {1, 2, -1, -4, -20},
                            {-8, -3, 4, 2, 1}, 
                            {3, 8, 10, 1, 3},
                            {-4, -1, 1, 7, -6}
                        };
    cout<<"Maximum Sum Rectangle in 2D using DP:\t"<<maxRectSum(a)<<endl;
    return 0;
}