#include <iostream>
using namespace std;

int G[100][100];
int n;
int start;
int ST[100];
int VIZ[100];
int top=0;

int read_data()
{
    cout<<"n=";
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            cout<<"G["<<i<<"]["<<j<<"]=";
            cin>>G[i][j];
        }
    cout<<"start=";
    cin>>start;
}

int push(int ST[], int nr)
{
    top++;
    ST[top]=nr;
    VIZ[nr]=1;
}

int pop(int ST[])
{
    if(top>=0)
    {
        top--;
        return ST[top+1];
    }
}

int isempty(int ST[])
{
    if(top==0)
        return 0;
    return 1;
}

int DFS_REC(int ST[], int node)
{
    if (isempty(ST))
    {
        int some;
        some=pop(ST);
        cout<<" "<<some;
        VIZ[some]=1;
        for(int i=1;i<=n;i++)
        {
            if((G[some][i]==1)&&(VIZ[i]==0))
                push(ST, i);
            DFS_REC(ST, i);
        }
    }
    return 0;
}

int main()
{
    read_data();
    push(ST, start);
    DFS_REC(ST, start);
}
