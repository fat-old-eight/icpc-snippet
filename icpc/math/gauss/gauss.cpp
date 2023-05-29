void gauss()
{
    for(int i=1;i<=2*n;i++)
    {
        int mx=i;
        for(int j=i+1;j<=2*n;j++)
        {
            if(fabs(g[mx][i])<fabs(g[j][i]))mx=j;
        }
        for(int j=1;j<=2*n+1;j++)swap(g[i][j],g[mx][j]);
        for(int j=1;j<=2*n;j++)
        {
            if(i!=j)
            {
                double p=g[j][i]/g[i][i];
                for(int k=1;k<=2*n+1;k++)g[j][k]-=g[i][k]*p;
            }
        }
    }
}