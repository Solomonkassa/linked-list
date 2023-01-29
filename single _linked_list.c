/**
 * Author solomon kassa .
 * ALx Africa Student . 
 * 
 * project to understand single list operations .
 */

#include <stdio.h>
#include <stdlib.h>
/**
 *  Creating nodes 
 *  @num - data
 *  @next - hold pointer .
 */
typedef struct Node 
{
    int num;
    struct Node *next;
    
} node;
//initalized nodes .
node *head = NULL,*last = NULL;

//function prototype .
void printing_linked_list ();
void creating_linked_list();

int main ()
{
  
    //Creating linked list .
    printf ("\nCreate linked list .\n");
    
    creating_linked_list ();
    printing_linked_list ();
    
    
    return (0);
}
void creating_linked_list()
{
    int val;
    
    while (1)
    {
        printf ("In put number .Enter -1 to exit . \n");
        scanf ("%d", &val);
        
        if (val == -1)
            break;
            
     //initalize node .
     node *tmp;
     
     //memory alloction .
     tmp = (node *) (malloc(sizeof (node)));
     
     //assign value .
     tmp->num = val;
     
     //linking next element .
     tmp->next = NULL;
     
     //For the first element .
     if(head == NULL)
     {
         head = tmp;
         last = tmp;
     }
     else 
     {
         last->next = tmp;
         last = tmp;
     }
     
     printing_linked_list (head);
    }
}

void printing_linked_list (node *d)
{
    //Tranverse linked list
    printf ("Full created linked list .\n");
    
    d = head;
    while (d != NULL)
    {
        printf("%d ",d->num);
        
        d = d->next;
    }
    printf("\n");
}
