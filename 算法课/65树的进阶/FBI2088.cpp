#include <bits/stdc++.h>
using namespace std;
char fun(string &s,int l ,int r)
{
    //ʲôʱ���˳�
    if(l==r)
    {
        char c = s[l]=='0'?'B':'I';
        cout<<c;// ������Ҷ�ӽڵ�ʱ��������Ҫ���ظ�Ҷ�ӽڵ�����ͣ�B �� I��
        //������������͡����ǵݹ�Ļ�����
        return c;
    }
    int mid = l+(r-l)/2;
    char lc = fun(s,l,mid);
    char rc = fun(s,mid+1,r);
    
    //��ǰ�ڵ�����͸������������������ж�
    char root;
    if(lc == rc)
    {
        root = lc;//���Һ������ʱ���ڵ���ӽڵ�����һ��
    }
    else
    {
        root = 'F';
    }
    cout<<root;
    return root;
}
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    fun(s,0,s.size()-1);
    cout<<endl;
    return 0;
}