#include<stdio.h>
#include<math.h>


long long int x[1000000],y[1000000];
int main () {

        long long int ans,l,h,pm,n,i,j,max,may,minx,miny;
        scanf("%lld",&n);
        pm=0;
        max=0;
        may=0;
        for (i=0;i<n;i++)
        {
                scanf("%lld %lld",&x[i],&y[i]);

                if (i==n-1)
                {
                        pm = pm + (fabs(x[n-1]-x[0]) + fabs(y[n-1]-y[0])) ;
                //      l = fabs(x[n-1]-x[0]); h = fabs(y[n-1]-y[0]);

                }

                if (i==0)
                continue;

                pm = pm + (fabs(x[i]-x[i-1]) + fabs(y[i]-y[i-1]));

        /*      l = fabs(x[i]-x[i-1]); h = fabs(y[i]-y[i-1]);

                if (l>max)
                max=l;
                
                if(h>may)
                may=h;*/

        }
        minx=x[0];
        miny=y[0];
        for (i=0;i<n;i++)
        {
                if(x[i]>max)
                max=x[i];

                if(y[i]>may)
                may=y[i];

                if (x[i]<minx)
                minx=x[i];

                if (y[i]<miny)
                miny=y[i];
        }


        ans = pm - 2*(max-minx+may-miny);
        printf("%lld\n",ans);
        return 0;
}

