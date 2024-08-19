#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in a linked list
typedef struct node {
    int value;          // Data stored in the node
    struct node *next;  // Pointer to the next node in the list
} Node;


void print_list(Node *head); // Print the linked list
Node *insert_head(Node *head, int new_value); // Insert a node at the head of the linked list
Node *insert_tail(Node *head, int new_value); // Insert a node at the tail of the linked list
Node *delete_head(Node *head); // Delete the node at the head of the linked list
Node *delete_tail(Node *head); // Delete the node at the tail of the linked list
int length(Node *head); // Length of linked list
Node *search(Node *head, int value); // Search for a matching value in the linked list
int count(Node *head, int value); // Count how many matches the value in the linked list
void replace_matches(Node *head, int find_value, int replace_value); // Replace value in the linked list
Node *delete_first_match(Node *head, int delete_value); // Delete first matching node
Node *delete_all_matches(Node *head, int delete_value); // Delete all matches
Node *append(Node *head1, Node *head2); // Append 2 lists
Node *reverse(Node *head); // Reverse Linked list
void bubble_sort(Node* head); // Sort
void remove_duplicates(Node *head); // Remove duplicates
Node *insert_after_value(Node *head, int new_value, int after_value); // Insert node after value
void delete_list(Node *head); // Delete list
Node *add_list(Node *list1, Node *list2); // Add 2 lists and update the values on list1
Node *duplicate(Node *list); // Duplicate linked list, return the new one