#include <stdio.h>

 

void main()

{

    int heap[10], no, i, j, c, root, temp;

 

    printf("\n Enter no of elements :");

    scanf("%d", &no);

    printf("\n Enter the nos : ");

    for (i = 0; i < no; i++)

       scanf("%d", &heap[i]);

    for (i = 1; i < no; i++)

    {

        c = i;

        do

        {

            root = (c - 1) / 2;             

            if (heap[root] < heap[c])   /* to create MAX heap array */

            {

                temp = heap[root];

                heap[root] = heap[c];

                heap[c] = temp;

            }

            c = root;

        } while (c != 0);

    }

 

    printf("Heap array : ");

    for (i = 0; i < no; i++)

        printf("%d\t ", heap[i]);

    for (j = no - 1; j >= 0; j--)

    {

        temp = heap[0];

        heap[0] = heap[j];  /* swap max element with rightmost leaf element */

        heap[j] = temp;

        root = 0;

        do 

        {

            c = 2 * root + 1;    /* left node of root element */

            if ((heap[c] < heap[c + 1]) && c < j-1)

                c++;

            if (heap[root]<heap[c] && c<j)    /* again rearrange to max heap array */

            {

                temp = heap[root];

                heap[root] = heap[c];

                heap[c] = temp;

            }

            root = c;

        } while (c < j);

    } 

    printf("\n The sorted array is : ");

    for (i = 0; i < no; i++)

       printf("\t %d", heap[i]);

    printf("\n Complexity : \n Best case = Avg case = Worst case = O(n logn) \n");

}


OUTPUT :
 Enter no of elements :8

 Enter the nos : 45 68 98 12 34 11 32 99

Heap array : 99	 98	 68	 45	 34	 11	 32	 12	  The sorted array is : 	 11	 12	 32	 34	 45	 68	 98	 99

 Complexity : 

 Best case = Avg case = Worst case = O(n logn) 

Process finished.
