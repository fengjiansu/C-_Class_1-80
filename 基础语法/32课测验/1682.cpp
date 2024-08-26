#include <bits/stdc++.h>

using namespace std;

struct people
{
    string name;
    int age;
    int rank;
};
bool cmp(people a,people b)
{
    if(a.age <=60 && b.age<=60)
    {
        return a.rank < b.rank;
    }
    if(a.age > 60 && b.age > 60)
    {
        return a.rank < b.rank;
    }
    return a.age > b.age;
}
int main()
{
   vector<people> v;
   int n;
   cin>>n;
   for(int i=0;i<n;i++)
   {
       people p;
       cin>>p.name>>p.age>>p.rank;
       v.push_back(p);
   }
   sort(v.begin(),v.end(),cmp);
   for(int i=0;i<n;i++)
   {
       cout<<v[i].name<<endl;
   }
   return 0;
}
