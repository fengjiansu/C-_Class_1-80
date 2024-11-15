#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int main()
{
    int t;
    cin>>t;
    int n,m,k;
    while(t--)
    {
        cin>>n>>m>>k;
        vector<vector<bool>> a(n,vector<bool>(m,true));
        vector<vector<bool>> b(n,vector<bool>(m,true));//检测有没有经过
        int x,y,d;
        cin>>x>>y>>d;
        x--;
        y--;
        
        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;
            for(int j=0;j<m;j++)
            {
                if(temp[j]=='x')
                {
                    a[i][j]=false;
                }
            }
        }
        b[x][y] = false;
        int cnt = 1;
        while(k--)
        {
            int x1 = x+dx[d];
            int y1= y+dy[d];
            //cout<<"x1: "<<x1<<" y1: "<<y1<<"d: "<<d<<endl;
            if(x1>=0&&x1<n&&y1>=0&&y1<m)
            {
                //cout<<"a[x1][y1]: "<<a[x1][y1];
                if(a[x1][y1])
                {
                    x = x1;
                    y = y1;
                    d = d;
                    if(b[x][y])
                    {
                        cnt++;
                        b[x][y] = false;
                    }
                    //a[x1][y1]=false;

                }
                else
                {
                    d = (d+1)%4;
                }
                
            }
            else
            {
                d = (d+1)%4;
            }
        }
        cout<<cnt<<endl;

    }
   

   return 0;
}
