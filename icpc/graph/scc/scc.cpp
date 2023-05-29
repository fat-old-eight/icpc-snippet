void tarjan(int x)
{
    dfn[x]=low[x]=++num;
    s[++top]=x;ins[x]=1;
    for(int i=head[x];i;i=a[i].nxt)
    {
        if(!a[i].e)continue;
        if(!dfn[a[i].w])
        {
            tarjan(a[i].w);
            low[x]=min(low[x],low[a[i].w]);
        }
        else if(ins[a[i].w])low[x]=min(low[x],dfn[a[i].w]);
    }
    if(dfn[x]==low[x])
    {
        tot++;
        int y;
        do
        {
            y=s[top--];ins[y]=0;
            c[y]=tot;
        }while(x!=y);
    }
}