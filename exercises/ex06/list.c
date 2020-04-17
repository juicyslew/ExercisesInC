/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}

void free_node(Node **node_ptr){
    free(*node_ptr);
    *node_ptr = NULL;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *current = *list;

    printf("[ ");
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    Node *current = *list;
    int val = -1;
    if (current == NULL){
        return val;
    }
    if (current->next == NULL){
        val = current->val;
        free_node(&current);
        return val;
    }


    while(current->next->next != NULL){
        current = current->next;
    }
    val = current->next->val;
    free_node(&(current->next));
    return val;
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node *current = *list;
    if (current == NULL){
        current = make_node(val, NULL);
        return;
    }

    while(current->next != NULL){
        current = current->next;
    }
    current->next = make_node(val, NULL);
    return;
    // FILL THIS IN!
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    Node *current = *list;
    if (current == NULL){
        return 0;
    }
    if (current->next == NULL){
        if (current->val = val){
            val = current->val;
            free_node(&current);
            return 1;
        }else{
            return 0;
        }
    }

    while(current->next->next != NULL){
        if (current->next->val == val){
            Node *removal = current->next;
            current->next = current->next->next;
            free_node(&removal);

            return 1;
        }
        current = current->next;
    }
    return 0;
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    Node *n_curr = *list;
    Node *n_next = n_curr; // Starts as curr to be changed at the start of the loop
    Node *n_last = NULL;
    
    while(n_curr != NULL){
        n_next = n_next->next; //this happens here so as to not ever be NULL without being caught
        n_curr->next = n_last;
        n_last = n_curr;
        n_curr = n_next;
    }
    *list = n_last;
    return;
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    print_list(list);

    push(list, retval+10);
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
