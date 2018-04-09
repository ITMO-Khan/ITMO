#include<fstream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
struct item
{
    int col,type;
    item(int c,int t)
    {
        col=c;
        type=t;
    }
};
bool cmp(item a,item b)
{
    return a.col < b.col;
}
vector<item>a;
int nexti[500007][5];
int main()
{
    ifstream fin("style.in");
    for(int i=1;i<=4;i++)
    {
        int n;
        fin>>n;
        for(int j=1;j<=n;j++)
        {
            int x;
            fin>>x;
            a.push_back(item(x,i));
        }
    }
    sort(a.begin(),a.end(),cmp);
    for(int i=1;i<=4;i++)
    {
        nexti[a.size()][i]=-1;
    }
    for(int i=a.size()-1;i>=0;i--)
    {
        for(int j=1;j<=4;j++)
        {
            nexti[i][j]=nexti[i+1][j];
        }
        nexti[i][a[i].type]=i;
    }
    long long ans=1000000000000,pans=-1;
    for(int i=0;i<a.size();i++)
    {
        long long cur=0;
        int poses[5];
        bool flag=false;
        for(int j=1;j<=4;j++)
        {
            if(nexti[i][j]==-1)
            {
                flag=true;
                break;
            }
            else
            {
              poses[j]=a[nexti[i][j]].col;
            }
        }
        for(int j=1;j<=4;j++)
        {
            for(int k=1;k<=4;k++)
            {
                cur+=abs(poses[k]-poses[j]);
            }
        }
        if(flag)
        {
            break;
        }
        if(cur<=ans)
        {
            ans=cur;
            pans=i;
        }
    }
    fin.close();
    ofstream fout("style.out");
    for(int i=1;i<=4;i++)
    {
        fout<<a[nexti[pans][i]].col<<' ';
    }
    fout.close();
}
