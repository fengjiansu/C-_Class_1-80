#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define REP(i,a,b) for(int i=a;i<b;i++)

/* 
�Ӻ�����������һ��Ԫ���ҵ����ڵ㡣
�����������ȷ��������ڵ��λ�á�
�ָ���������������������������֡�
�������������������Ĵ�С���ָ���������
�ݹ鴦������������
������ڵ� + ������ + ��������˳�򣬾������������


 */


string fun(string in, string post)
{
    if(in.size()==0)
        return "";
    char root = post.back();
    //��������
    int rootPos= in.find(root);

    string l_in = in.substr(0, rootPos);
    string r_in = in.substr(rootPos + 1);

    string l_post = post.substr(0, l_in.size());
    string r_post = post.substr(l_in.size(), r_in.size());

    string l_pre=fun(l_in, l_post);
    string r_pre=fun(r_in, r_post);
    return root+l_pre+r_pre;
}

void build(string &in,string &post,int l_in,int r_in,int l_post,int r_post)
{
    if(l_in>r_in || l_post>r_post) return;
    char root = post[r_post];
    cout<<root;
    int rootPos= in.find(root);
    int lSize=rootPos-l_in;
    build(in,post,l_in,rootPos-1,l_post,l_post+lSize-1);
    build(in,post,rootPos+1,r_in,l_post+lSize,r_post-1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string in, post;
    cin >> in >> post;
    cout<<fun(in, post);
    return 0;
}
