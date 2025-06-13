#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

struct sides{
  long long a;
  long long b;
  long long c;
};

// Add any helper functions you may need here


int countDistinctTriangles(vector <sides> arr)
{
  // Write your code here
  int n=arr.size();
  int i;
  vector<vector<long>> T(n,vector<long>(3));
  for(i=0;i<arr.size();i++)
    {
       T[i][0]=arr[i].a;
       T[i][1]=arr[i].b;
       T[i][2]=arr[i].c;
       sort(T[i].begin(),T[i].end());
    }
    T.erase(unique(T.begin(),T.end()),T.end());
  return T.size();
}
int main() 
{

  vector<sides> arr_1 = {{7, 6, 5}, {5, 7, 6}, {8, 2, 9}, {2, 3, 4}, {2, 4, 3}};
  int expected_1 = 3;
  int output_1 = countDistinctTriangles(arr_1);
  cout<<output_1;
//   vector<sides> arr_2 = {{3, 4, 5}, {8, 8, 9}, {7, 7, 7}};
//   int expected_2 = 3;
//   int output_2 = countDistinctTriangles(arr_2);
  return 0;
}
  
