/*
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if( q == NULL){
       printf("The memory isn't available!");
       return NULL;
   }//?????????
    /* What if malloc returned NULL? */
    q->size = 0;
    q->head = NULL;
    q->tail = NULL; 
    return q;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *node;
    while(q->size !=0){
       node = q_remove_head(q,q->tail,q_size) ;//?
       free(node);
    }
    free(q);
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh = malloc(sizeof(list_ele_t));
    newh-> value = *s;
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
      if( (newh == NULL) || (q == NULL)){
      printf("The memory is full");   
      return false;
      }
    /* What should you do if the q is NULL? */
   if( q->size == 0 ){
    q-> head = newh;
    q-> tail = newh;//
    }else{
    newh->next = q->head;
    q->head = newh;
   }
    q->size ++;
    free(s);
    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
    /* You need to write the complete code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *new = malloc(sizeof(list_ele_t));
     new->value = *s;
     new->next = NULL;
    if((q == NULL) || (new == NULL)){
      return false;
    }
    if(q->size == 0){
      q->head = new;
      q->tail = new;
    }else{
      q->tail->next = new;
      q->tail = new;
    }
    q->size ++;
    free(s);
    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    
    /* You need to fix up this code. */
    list_ele_t *temp = malloc(sizeof (list_ele_t));
    for(int i=0 ; i < bufsize-1 ; i++){
         temp->value = *(sp+i);//null???
      }
    if((q == NULL) || (temp == NULL)){
         return false;
    }
    if(q->size == 0){
         return NULL;
    }else{
         temp->next = q->head->next;
         q->head = temp->next;
         q->head->next = NULL;
    }
      q->size --;     
      free(sp);
      free(temp);
      return true;
  
     
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
    list_ele_t *temp = malloc(sizeof(list_ele_t));
    q->head = temp->next;
    int qsize;
    while(temp->next){
      qsize++;
      temp->next = q->head->next;
    }
    printf("q_size = %d",size);
    free(temp);
    return 0;
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
    queue_t *q2 = malloc(sizeof(queue_t));
    if(q2 == NULL){
         return ;//
    }
    char *copy;
    while(q->size !=0){
    copy = q_remove_head(q, q->tail , q_size);
    q_insert_tail(q2,copy);
    }
    
}
