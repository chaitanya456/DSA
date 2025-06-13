#include<bits/stdc++.h>
using namespace std;
vector<int> getIntersection(vector<vector<int>>& sets);
int main()
{
    vector < vector <int> > sets;
    vector <int> set1;
    set1.push_back(1);
    set1.push_back(1);
    set1.push_back(2);
    set1.push_back(2);
    set1.push_back(5);

    sets.push_back(set1);

    vector <int> set2;
    set2.push_back(1);
    set2.push_back(1);
    set2.push_back(4);
    set2.push_back(3);
    set2.push_back(5);
    set2.push_back(9);

    sets.push_back(set2);

    vector <int> set3;
    set3.push_back(1);
    set3.push_back(1);
    set3.push_back(2);
    set3.push_back(3);
    set3.push_back(5);
    set3.push_back(6);

    sets.push_back(set3);
    vector<int> res=getIntersection(sets);
    cout<<"Intersection of N Lists:\t";
    for(auto x: res)
    cout<<x<<" ";
    return 0;
}
vector<int> getIntersection(vector<vector<int>>& sets)
{
    vector<int> res;
    int min_size=INT_MAX;
    int i;
    int min_index_set=0;
    for(i=0;i<sets.size();i++)
    {
        sort(sets[i].begin(),sets[i].end());
        if(sets[i].size()<min_size)
        {
            min_size=sets[i].size();
            min_index_set=i;
        }
    }
    map<int,int>m;
    for (i=0;i<sets[min_index_set].size();i++)
    m[sets[min_index_set][i]]++;
    for(auto &x:m)
    {
        int element=x.first;
        int freq=x.second;
        bool flag=1;
        for(i=0;i<sets.size();i++)
        {
            if(i!=min_index_set)
            {
                if(binary_search(sets[i].begin(),sets[i].end(),element))
                {
                    int elem_count=count(sets[i].begin(),sets[i].end(),element);
                    if(elem_count<freq)
                    freq=elem_count;
                }
                else
                {
                    flag=0;
                    // break;
                }
            }
        }
        if(flag)
        {
            while(freq--)
            res.push_back(element);
        }
    }
    return res;
}