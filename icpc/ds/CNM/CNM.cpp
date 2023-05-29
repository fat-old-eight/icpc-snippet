struct LC_tree
{
    struct sss
    {
        int mx;
        #define mx(x) tree[x].mx
    }tree[200005];
    struct edge
    {
        double k,b;
    }e[100005];
    double calc(int i,int x){return e[i].k*(x-1)+e[i].b;}
    void change(int x,int l,int r,int p)
    {
        if(calc(p,l)>calc(mx(x),l)&&calc(p,r)>calc(mx(x),r)){mx(x)=p;return;}
        if(calc(p,l)<=calc(mx(x),l)&&calc(p,r)<=calc(mx(x),r))return; 
        int mid=(l+r)>>1;
        double m1=calc(mx(x),mid),m3=calc(p,mid);
        if(e[mx(x)].k<e[p].k)
        {
            if(m1<=m3){change(x*2,l,mid,mx(x));mx(x)=p;}
            else change(x*2+1,mid+1,r,p);
        }
        else if(e[mx(x)].k>e[p].k)
        {
            if(m1<=m3){change(x*2+1,mid+1,r,mx(x));mx(x)=p;}
            else change(x*2,l,mid,p);
        }
        else if(e[mx(x)].b<e[p].b)mx(x)=p;
    }
    double ask_max(int x,int l,int r,int p)
    {
        if(l==r)return calc(mx(x),p);
        int mid=(l+r)>>1;
        if(p<=mid)return max(ask_max(x*2,l,mid,p),calc(mx(x),p));
        else return max(ask_max(x*2+1,mid+1,r,p),calc(mx(x),p));
    }
};