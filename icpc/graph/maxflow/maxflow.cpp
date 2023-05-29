bool bfs()
{
    memset(d,0,sizeof(d));
    while(q.size())q.pop();
    q.push(S);
    d[S]=1;
    now[S]=head[S];
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=head[x];i;i=a[i].nxt)
        {
            if(a[i].e&&!d[a[i].w])
            {
                q.push(a[i].w);
                now[a[i].w]=head[a[i].w];
                d[a[i].w]=d[x]+1;
                if(a[i].w==T)return 1;
            }
        }
    }
    return 0;
}
int dinic(int x,int flow)
{
    if(x==T)return flow;
    int rest=flow;
    for(int i=now[x];i&&rest;i=a[i].nxt)
    {
        now[x]=i;
        if(a[i].e&&d[a[i].w]==d[x]+1)
        {
            int k=dinic(a[i].w,min(rest,a[i].e));
            if(!k)d[a[i].w]=0;
            a[i].e-=k;
            a[i%2?i+1:i-1].e+=k;
            rest-=k;
        }
    }
    return flow-rest;
}