#include<bits/stdc++.h>
using namespace std;
void func(vector<int>&a, int n, int target);
int main()
{
    vector<int>a={1, 4, 45, 6, 10, 8};
    int target=13;
    // func(a,a.size(),target);
    func(a,a.size(),target);
    return 0;
}
// void func(vector<int>&a, int n, int target)
// {
//     int i,j;
//     for(i=0;i<n;i++)
//     {
//         int val=a[i];
//         unordered_set<int>s;
//         for(j=i+1;j<n;j++)
//         {
//             int tempSum=target-val-a[j];
//             if(s.find(tempSum)!=s.end())
//             {
//                 cout<<"Triplet found";
//                 break;
//             }
//             s.insert(a[j]);
//         }
//     }
// }
void func(vector<int>&a, int n, int target)
{
    sort(a.begin(),a.end());
    int i=0,j=n-1;
    for(;i<n-2;i++)
    {
        int l=i+1,r=j;
        int tempSum=target-a[i];
        while(l<r)
        {
            if(a[l]+a[r]==tempSum)
            {
                cout<<"Triplet Found";
                break;
            }
            else if(a[l]+a[r]<tempSum)
            l++;
            else r--;
        }
    }
}