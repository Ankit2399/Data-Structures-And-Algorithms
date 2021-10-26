/* Shell Sort is mainly a variation of Insertion Sort. In insertion sort, we move elements only one position ahead. 
When an element has to be moved far ahead, many movements are involved. */
   
   /* C Program for Sorting an Array using Shell Sort */
#include<stdio.h>
#define MAX 100

int main()
{

        int arr[MAX],i,j,k,n,incr;

        printf("\nEnter the number of elements : ");
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
                printf("\nEnter element %d : ",i+1);
                scanf("%d",&arr[i]);
        }

        printf("\nEnter maximum increment (odd value) : ");
        scanf("%d",&incr);

        /*Shell sort*/
        while(incr>=1)
        {
                for(i=incr; i<n; i++)
                {
                        k=arr[i];
                        for(j=i-incr; j>=0 && k<arr[j]; j=j-incr)
                                arr[j+incr]=arr[j];
                        arr[j+incr]=k;
                }
                incr=incr-2; /*Decrease the increment*/
        }/*End of while*/

        printf("\nSorted list is :\n");
        for(i=0; i<n; i++)
                printf("  %d  ", arr[i]);
        printf("\n");

        return 0;
}

