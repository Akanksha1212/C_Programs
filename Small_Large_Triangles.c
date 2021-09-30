
void swap(triangle* a,triangle* b)
{
    triangle temp=*a;
    *a=*b;
    *b=temp;
}
int cmp(triangle tr)
{
    int a=tr.a;
    int b=tr.b;
    int c=tr.c;
    return (a+b+c)*(a-b+c)*(a+b-c)*(-a+b+c);
}
void sort_by_area(triangle* tr, int n) {
    /**
    * Sort an array a of the length n
    */
    for(int i=0;i<n;i++)
    {
        int swapped=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(cmp(tr[j])>cmp(tr[j+1]))
             swap(&tr[j],&tr[j+1]);
            swapped=1;
        }
        if(swapped==0)
            break;
    }
   
}

// You can visit this link for question :-
// https://www.hackerrank.com/challenges/small-triangles-large-triangles/submissions/code/113637557
