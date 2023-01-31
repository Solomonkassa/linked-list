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
void insert_at_last(int val);
void insert_at_first(int val);

int main ()
{
    
    int val;
  
    //Creating linked list .
    printf ("\nCreate linked list .\n");
    
    creating_linked_list ();
    printing_linked_list ();
    
     //Insert value at first position to existing Linked List
    printf("\nInsert new item at first\n");
    scanf("%d", &val);
    insert_at_first(val);
    printing_linked_list();
    
     //Insert value at last position to existing Linked List
    printf("\nInsert new item at last\n");
    scanf("%d", &val);
    
    insert_at_last(val);
    printing_linked_list();
    
    
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

void insert_at_last(int val)
{
    node *tmp;
    tmp = (node *) malloc(sizeof(node));

    tmp->num=val;
    tmp->next=NULL;

    //For the 1st element
    if(head==NULL)
    {
        head=tmp;
        last=tmp;
    }
    else
    {
        last->next=tmp;
        last=tmp;
    }

}
void insert_at_first(int val)
{
    node *tmp;
    
    //Allocate memory . 
    tmp = (node*)malloc(sizeof(node));
    //Assign value .
    tmp->num = val;
    //Connect nodes .
    tmp->next = head;
    
    head = tmp;
    

