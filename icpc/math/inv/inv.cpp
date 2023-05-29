const int mod = 998'244'353;

int p[1000005];

void get_inv(const int n)
{
    p[1]=1;
    for(int i=2;i<=n;i++)
    {
        p[i]=(long long)(mod-mod/i)*p[mod%i]%mod;
    }
}