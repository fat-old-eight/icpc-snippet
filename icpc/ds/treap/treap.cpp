#include<iostream>
using namespace std;
struct FHQ
{
    int cnt,root;
    struct sss
    {
        int r,l,s,w,v;
        #define l(x) tree[x].l
        #define r(x) tree[x].r
        #define s(x) tree[x].s
        #define w(x) tree[x].w
        #define v(x) tree[x].v
    }tree[100005];
    void build(){cnt=0;}
    int New(int x)
    {
        w(++cnt)=rand();
        v(cnt)=x;
        s(cnt)=1;
        return cnt;
    }
    void pushup(int x){s(x)=s(l(x))+s(r(x))+1;}
    void splitv(int root,int key,int &x,int &y)
    {
        if(!root)x=y=0;
        else if(v(root)<=key)
        {
            x=root;
            splitv(r(root),key,r(x),y);
            pushup(root);
        }
        else
        {
            y=root;
            splitv(l(root),key,x,l(y));
            pushup(root);
        }
    }
    void splits(int root,int s,int &x,int &y)
    {
        if(!root)x=y=0;
        else if(s(l(root))<s)
        {
            x=root;
            splits(r(root),s-s(l(root))-1,r(x),y);
            pushup(root);
        }
        else
        {
            y=root;
            splits(l(root),s,x,l(y));
            pushup(root);
        }
    }
    int merge(int x,int y)
    {
        if(!x||!y)return x^y;
        else if(w(x)>w(y))
        {
            r(x)=merge(r(x),y);
            pushup(x);
            return x;
        }
        else
        {
            l(y)=merge(x,l(y));
            pushup(y);
            return y;
        } 
    }
}T1;