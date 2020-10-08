#include<stdio.h>
#include<string.h>

int i,j,l,m,n=0,o,p,nv,z=0,x=0;
char str[10],temp,temp2[10],temp3[20],*ptr;
FILE *op;


struct prod
{
    char lhs[10],rhs[10][10],ft[10],fol[10];
    int n;
}pro[10];

void findter()
{
    int k,t;
    for(k=0;k<n;k++)
    {
        if(temp==pro[k].lhs[0])
        {
            for(t=0;t<pro[k].n;t++)
            {
                if( pro[k].rhs[t][0]<65 || pro[k].rhs[t][0]>90 )
                    pro[i].ft[strlen(pro[i].ft)]=pro[k].rhs[t][0];
                else if( pro[k].rhs[t][0]>=65 && pro[k].rhs[t][0]<=90 )
                {
                    temp=pro[k].rhs[t][0];
                    if(temp=='S')
                        pro[i].ft[strlen(pro[i].ft)]='#';
                    findter();
                }
            }
            break;
        }
    }
}

void findfol()
{
    int k,t,p1,o1,chk;
    char *ptr1;
    for(k=0;k<n;k++)
    {
        chk=0;
        for(t=0;t<pro[k].n;t++)
        {
            ptr1=strchr(pro[k].rhs[t],temp);
            if( ptr1 )
            {
                p1=ptr1-pro[k].rhs[t];
                if(pro[k].rhs[t][p1+1]>=65 && pro[k].rhs[t][p1+1]<=90)
                {
                    for(o1=0;o1<n;o1++)
                        if(pro[o1].lhs[0]==pro[k].rhs[t][p1+1])
                        {
                                strcat(pro[i].fol,pro[o1].ft);
                                chk++;
                        }
                }
                else if(pro[k].rhs[t][p1+1]=='\0')
                {
                    temp=pro[k].lhs[0];
                    if(pro[l].rhs[j][p]==temp)
                        continue;
                    if(temp=='S')
                        strcat(pro[i].fol,"$");
                    findfol();
                    chk++;
                }
                else
                {
                    pro[i].fol[strlen(pro[i].fol)]=pro[k].rhs[t][p1+1];
                    chk++;
                }
            }
        }
        if(chk>0)
            break;
    }
}

int main()
{
    FILE *f;
    //clrscr();

    for(i=0;i<10;i++)
        pro[i].n=0;

    f=fopen("first&follow.txt","r");//Input file place your grammar here sample grammar is also placed 
    while(!feof(f))
    {
        fscanf(f,"%s",pro[n].lhs);
        if(n>0)
        {
            if( strcmp(pro[n].lhs,pro[n-1].lhs) == 0 )
            {
                pro[n].lhs[0]='\0';
                fscanf(f,"%s",pro[n-1].rhs[pro[n-1].n]);
                pro[n-1].n++;
                continue;
            }
        }
        fscanf(f,"%s",pro[n].rhs[pro[n].n]);
        pro[n].n++;
        n++;
    }

    printf("\n\nTHE GRAMMAR IS AS FOLLOWS\n\n");
    for(i=0;i<n;i++)
        for(j=0;j<pro[i].n;j++)
            printf("%s -> %s\n",pro[i].lhs,pro[i].rhs[j]);

    pro[0].ft[0]='#';
    for(i=0;i<n;i++)
    {
        for(j=0;j<pro[i].n;j++)
        {
            if( pro[i].rhs[j][0]<65 || pro[i].rhs[j][0]>90 )
            {
                pro[i].ft[strlen(pro[i].ft)]=pro[i].rhs[j][0];
            }
            else if( pro[i].rhs[j][0]>=65 && pro[i].rhs[j][0]<=90 )
            {
                temp=pro[i].rhs[j][0];
                if(temp=='S')
                    pro[i].ft[strlen(pro[i].ft)]='#';
                findter();
            }
        }
    }

    printf("\n\nFIRST\n");
    for(i=0;i<n;i++)
    {
        printf("\n%s -> ",pro[i].lhs);
        for(j=0;j<strlen(pro[i].ft);j++)
        {
            for(l=j-1;l>=0;l--)
                if(pro[i].ft[l]==pro[i].ft[j])
                    break;
            if(l==-1)
                printf("%c",pro[i].ft[j]);
        }
    }

    for(i=0;i<n;i++)
        temp2[i]=pro[i].lhs[0];
    pro[0].fol[0]='$';
    for(i=0;i<n;i++)
    {
        for(l=0;l<n;l++)
        {
            for(j=0;j<pro[i].n;j++)
            {
                ptr=strchr(pro[l].rhs[j],temp2[i]);
                if( ptr )
                {
                    p=ptr-pro[l].rhs[j];
                    if(pro[l].rhs[j][p+1]>=65 && pro[l].rhs[j][p+1]<=90)
                    {
                        for(o=0;o<n;o++)
                            if(pro[o].lhs[0]==pro[l].rhs[j][p+1])
                                    strcat(pro[i].fol,pro[o].ft);
                    }
                    else if(pro[l].rhs[j][p+1]=='\0')
                    {
                        temp=pro[l].lhs[0];
                        if(pro[l].rhs[j][p]==temp)
                            continue;
                        if(temp=='S')
                            strcat(pro[i].fol,"$");
                        findfol();
                    }
                    else
                        pro[i].fol[strlen(pro[i].fol)]=pro[l].rhs[j][p+1];
                }
            }
        }
    }

    printf("\n\nFOLLOW\n");
    for(i=0;i<n;i++)
    {
        printf("\n%s -> ",pro[i].lhs);
        for(j=0;j<strlen(pro[i].fol);j++)
        {
            for(l=j-1;l>=0;l--)
                if(pro[i].fol[l]==pro[i].fol[j])
                    break;
            if(l==-1)
                printf("%c",pro[i].fol[j]);
        }
    }
    printf("\n");
    //getch();
}