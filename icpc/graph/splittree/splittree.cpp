void dfs1(int x,int fa)
{
    f[x]=fa;
    d[x]=d[fa]+1;
    s[x]=1;
    int id=0,mx=0;
    for(int i=head[x];i;i=a[i].nxt)
    {
        if(a[i].w!=fa)
        {
            dfs1(a[i].w,x);
            s[x]+=s[a[i].w];
            if(s[a[i].w]>mx)id=a[i].w,mx=s[a[i].w];
        }
    }
    son[x]=id;
}
void dfs2(int x,int tp)
{
    top[x]=tp;
    dfn[x]=++cnt;
    if(!son[x])return;
    dfs2(son[x],tp);
    for(int i=head[x];i;i=a[i].nxt)
    {
        if(f[x]!=a[i].w&&a[i].w!=son[x])dfs2(a[i].w,a[i].w);
    }
}
void change1(int x,int y,int p)
{
    while(top[x]!=top[y])
    {
        if(d[top[x]]<d[top[y]])swap(x,y);
        T1.change(1,dfn[top[x]],dfn[x],p);
        x=f[top[x]];
    }
    if(d[x]<d[y])swap(x,y);
    T1.change(1,dfn[y],dfn[x],p);
}