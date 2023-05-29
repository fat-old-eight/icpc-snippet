bool spfa()
{
    memset(d,0x3f,sizeof(d));
    while(q.size())q.pop();
    q.push(S);
    d[S]=0;
    vis[S]=1;
    now[S]=head[S];
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        vis[x]=0;
        for(int i=head[x];i;i=a[i].nxt)
        {
            if(a[i].e&&d[a[i].w]>d[x]+a[i].r)
            {
                now[a[i].w]=head[a[i].w];
                d[a[i].w]=d[x]+a[i].r;
                if(!vis[a[i].w])q.push(a[i].w),vis[a[i].w]=1;
            }
    }
    }
    return d[T]!=0x3f3f3f3f3f3f3f3f;
}
int dinic(int x,int flow)
{
    if(x==T)return flow;
    vis[x]=1;
    int rest=flow;
    for(int i=now[x];i&&rest;i=a[i].nxt)
    {
        now[x]=i;
        if(!vis[a[i].w]&&a[i].e&&d[a[i].w]==d[x]+a[i].r)
        {
            int k=dinic(a[i].w,min(rest,a[i].e));
            if(!k)d[a[i].w]=0;
            mx+=k*a[i].r;
            a[i].e-=k;
            a[i%2?i+1:i-1].e+=k;
            rest-=k;
        }
    }
    vis[x]=0;
    return flow-rest;
}