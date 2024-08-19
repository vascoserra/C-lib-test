# Linked Lists

1. [Introduction](#introduction)
2. [Node Structure](#node-structure)
3. [Print a Linked List](#print-a-linked-list)
4. [Insertion](#insertion)
    - [Insert at Head](#insert-at-head)
    - [Insert at Tail](#insert-at-tail)
5. [Deletion](#deletion)
    - [Delete Head](#delete-head)
    - [Delete Tail](#delete-tail)
6. [Operations](#operations)
    - [Length](#length)
    - [Search](#search)
    - [Count](#count)
    - [Replace](#replace)
7. [Delete Matching Nodes](#delete-matching-nodes)
    - [Delete First Matching Node](#delete-first-matching-node)
    - [Delete All Matching Nodes](#delete-all-matching-nodes)
8. [Append, Reverse, Sort, and Remove Duplicates](#append-reverse-sort-and-remove-duplicates)
    - [Append](#append)
    - [Reverse](#reverse)
    - [Sort](#sort)
    - [Remove Duplicates](#remove-duplicates)
9. [Insert After Value and Delete List](#insert-after-value-and-delete-list)
    - [Insert After Value](#insert-after-value)
    - [Delete List](#delete-list)
10. [Add Two Lists and Duplicate](#add-two-lists-and-duplicate)
    - [Add Two Lists](#add-two-lists)
    - [Duplicate](#duplicate)

## Introduction

- Linked lists provide dynamic memory allocation, avoiding memory fragmentation.
- Easier to modify compared to arrays.
- Fundamental structure consists of nodes, each storing data and a reference to the next node.
- A pointer to the head is used to access the list.

## Node structure

```c
typedef struct node {
    int value;
    struct node *next;
} Node;
```

- Node: Used to declare instances of the struct.
- node: The name of the struct.
- int value: Holds data (e.g., an integer).
- struct node *next: Points to the next node.

## Print a linked list

```c
/ Print the linked list
void print_list(Node *head) {
    Node *current;  // Pointer to traverse the list
    current = head; // Start from the head of the list
    int i = 0;      // Counter for node numbering

    // Traverse the list and print node values
    while (current != NULL) {
        printf("Node %d : %d\n", i, current->value);
        i++;
        current = current->next; // Advance to next node
    }
}
```

- Node *head: We pass the address of the head from main (e.g., (&first)).
- Node *current;: A pointer to traverse the list.
- current = current->next;: This statement moves our pointer to the next node in the list.

## Insertion

### Insert at head

```c
// Insert a node at the head of the linked list:
Node *insert_head(Node *head, int new_value) {
    Node *new_node = calloc(1, sizeof(Node)); // Allocate memory for the new node
    new_node->value = new_value;               // Set the value for the new node

    // If the list is empty, the new node becomes the head
    if (head == NULL)
        return new_node;
    else {
        new_node->next = head;  // Point the new node to the current head
        return new_node;        // The new node becomes the new head
    }
}
```

### Insert at tail

```c
// Insert a node at the tail of the linked list
Node *insert_tail(Node *head, int new_value) {
    Node *new_node = calloc(1, sizeof(Node)); // Allocate memory for the new node
    new_node->value = new_value;               // Set the value for the new node

    // If the list is empty, the new node becomes the head
    if (head == NULL)
        return new_node;
    else {
        Node *current = head;

        // Traverse to the end of the list
        while (current->next != NULL) {
            current = current->next;
        }

        // Append the new node to the end of the list
        current->next = new_node;
        return head;  // Return the head (unchanged)
    }
}
```

## Deletion

### Delete head

```c
// Delete the node at the head of the linked list
Node *delete_head(Node *head) {
    if (head == NULL)  // If the list is empty
        return NULL;
    else {
        Node *to_return = head->next;  // Point to the new head
        free(head);  // Free the memory allocated for the previous head
        return to_return;  // Return the new head
    }
}
```

### Delete tail

```c
// Delete the node at the tail of the linked list
Node *delete_tail(Node *head) {
    if (head == NULL)  // If the list is empty
        return NULL;
    else if (head->next == NULL)  // If there's only one node in the list
        return head;  // Return the head as the list will be empty after deletion
    else {
        Node *current = head;  // Pointer to traverse the list
        Node *prev = NULL;     // Pointer to keep track of the previous node

        // Traverse to the end of the list while keeping track of the previous node
        while (current->next != NULL) {
            prev = current;
            current = current->next;
        }

        // Update the previous node to skip the last node (the tail)
        prev->next = NULL;

        free(current);  // Free the memory allocated for the previous tail
        return head;    // Return the head (unchanged)
    }
}
```

## Operations

### Length

```c
int length(Node *head)
{
    Node *current = head;
    int length = 0; // Initiate counter

    while (current != NULL)
    {
        length++; // Every time we pass a node we increase length by 1 
        current = current->next;
    }
    return length;
}
```

### Search

```c
// Search for a matching value in linked list
Node *search(Node *head, int value) {
    Node *current = head;

    while (current != NULL) {
        if (current->value == value) {
            printf("Value %d found\n", value);
            return current;  // Return the node containing the value
        }

        current = current->next;
    }

    printf("Value %d not found\n", value);
    return NULL;  // Return NULL if the value is not found in the list
}
```

### Count

```c
// Count how many matches the value in linked list
int count(Node *head, int value) {
    Node *current = head;
    int counter = 0;

    while (current != NULL) {   // Transverse the list
        if (current->value == value) 
        {
            counter++; // Increase counter when value match
        }

        current = current->next;
    }
    return counter; // Retrive counter 
}
```

### Replace

```c
// Replace value in the linked list
void replace_matches(Node *head, int find_value, int replace_value) {
    Node *current = head;  // Initialize a pointer to traverse the list starting from the head

    // Traverse the list
    while (current != NULL) {
        // Check if the current node's value matches the value to be replaced
        if (current->value == find_value) {
            current->value = replace_value;  // Replace the value with the specified replacement value
        }

        // Move to the next node in the list
        current = current->next;
    }
}
```

## Delete matching nodes

### Delete first matching node

```c
// Delete first matching node
Node *delete_first_match(Node *head, int delete_value) {
    if (head == NULL) 
        return NULL;  // Return NULL if the list is empty
    
    if (head->value == delete_value) {
        // If the first node matches the value to be deleted
        Node *temp = head->next;
        free(head);  // Free the memory for the first node
        return temp;  // Return the updated head (second node becomes the new head)
    }
    
    Node *current = head->next;  // Pointer to traverse the list starting from the second node
    Node *prev = head;  // Pointer to keep track of the previous node

    // Traverse the list
    while(current != NULL) {
        // Check if the current node's value matches the value to be deleted
        if (current->value == delete_value) {
            // Update pointers to remove the node with the specified value
            prev->next = current->next;
            free(current);  // Free the memory for the node to be deleted
            return head;  // Return the head (no change if the first node wasn't the match)
        }

        // Move to the next node
        prev = current;
        current = current->next;
    }

    return head;  // Return the head (no match found)
}
```

### Delete all matching nodes

```c
// Delete all matches
Node *delete_all_matches(Node *head, int delete_value) {
    Node *current = head;    
    Node *prev = NULL;

    while (current != NULL) {
        if (current->value == delete_value) {
            // Value matches, node to be deleted
            Node *tmp = current;

            if (current == head) {
                // If it's the head of the list
                head = current->next;  // Update the head
                current = head;  // Move current to the new head
            } else {
                // Node is not the head
                prev->next = current->next;  // Update the 'next' of the previous node
                current = current->next;  // Move current forward
            }

            free(tmp);  // Free the memory for the node
        } else {
            // Value does not match, move to the next node
            prev = current;  // Move the previous pointer
            current = current->next;  // Move the current pointer
        }
    }

    return head;  
}
```

## Append, Reverse, Sort and Remove duplicates

### Append

```c
// Append 2 lists
Node *append(Node *head1, Node *head2)
{
    if (head1 == NULL)  return head2; // head1 is empty
    
    Node *currrent = head1;
    while (currrent->next != NULL) currrent = currrent->next; // Transverse untill end of the list1
    currrent->next = head2; // Point last node to the head2
    return head1;
}
```

### Reverse

```c
// Reverse Linked list
Node *reverse(Node *head)
{
    if (head == NULL) return NULL;
    if (head->next == NULL) return head;
    
    Node *current = head;  // Pointer to the current node
    Node *next_node = head->next;  // Pointer to the next node

    current->next = NULL;  // Make the first node the new tail of the list

    while (next_node != NULL) {
        Node *tmp = next_node->next;  // Save the next node to avoid losing it
        next_node->next = current;   // Reverse the link to the previous node
        current = next_node;   // Move forward in the list
        next_node = tmp;   // Move forward in the list
    }

    return current;
}
```

### Sort

```c
// Sort
void bubble_sort(Node* head) {
    // Base case: if the list is empty or has only one element
    if (head == NULL || head->next == NULL)
        return;

    int swapped;
    Node* current;
    Node* last = NULL;

    while (1) {
        swapped = 0;  // Flag to check if any elements were swapped in this pass
        current = head;

        // Traverse the list and compare adjacent nodes
        while (current->next != last) {
            if (current->value > current->next->value) {
                // Swap the values
                int temp = current->value;
                current->value = current->next->value;
                current->next->value = temp;
                swapped = 1;  // Set swapped flag if a swap occurred
            }
            current = current->next;
        }

        last = current;  // Mark the last node as sorted

        // If no two elements were swapped, the list is sorted
        if (!swapped)
            break;  // Exit the loop if no elements were swapped
    }
}
```

### Remove duplicates

```c
// Remove duplicates
void remove_duplicates(Node *head) {
    // Check if the list is empty or has only one node
    if (head == NULL || head->next == NULL)
        return;

    Node *current1, *current2, *duplicate;
    current1 = head;

    // Traverse the list with the first pointer
    while (current1 != NULL && current1->next != NULL) {
        current2 = current1;

        // Traverse the list with the second pointer
        while (current2->next != NULL) {
            // Check if the value of the current node is equal to the value of the next node
            if (current1->value == current2->next->value) {
                // If a duplicate is found, remove the duplicate node
                duplicate = current2->next;
                current2->next = current2->next->next;
                free(duplicate);  // Free the memory of the duplicate node
            } else
                current2 = current2->next;  // Move the second pointer to the next node
        }
        current1 = current1->next;  // Move the first pointer to the next node
    }
}
```

## Insert After Value and Delete List

### Insert after value

```c
// Insert node after value
Node *insert_after_value(Node *head, int new_value, int after_value) {
    Node *new_node = calloc(1, sizeof(Node));  // Allocate memory for the new node
    new_node->value = new_value;                // Set the value for the new node

    if (head == NULL) 
        return new_node;  // If the list is empty, the new node becomes the head
    else {
        Node *current = head;

        // Traverse the list to find the node with the specified value
        while(current->next != NULL) {
            // If the specified value is found, insert the new node after it
            if (current->value == after_value) {
                new_node->next = current->next;  // Set the new node's next to the current node's next
                current->next = new_node;  // Set the current node's next to the new node
                return head;
            } else
                current = current->next;  // Move to the next node
        }

        // If the specified value was not found, insert the new node at the end of the list
        new_node->next = current->next;  // Set the new node's next to NULL (end of the list)
        current->next = new_node;  // Set the current node's next to the new node
        return head;
    }
}
```

### Delete list

```c
// Delete list
void delete_list(Node *head) {
    Node *current = head;
    Node *next;

    while (current != NULL) {
        next = current->next;  // Save the next node
        free(current);         // Free the current node
        current = next;        // Move to the next node
    }
}
```

## Add two lists and Duplicate

### Add two lists

```c
// Add 2 lists and update the values on list1
Node *add_list(Node *list1, Node *list2) {
    Node *current1 = list1;  // Pointer to traverse the first list
    Node *current2 = list2;  // Pointer to traverse the second list

    // Check if either list is empty
    if (list1 == NULL || list2 == NULL)
        return NULL;  // If either list is empty, return NULL

    // Traverse both lists and add values from list2 to list1
    while (current1 != NULL && current2 != NULL) {
        // Add the value from the second list to the corresponding node in the first list
        current1->value += current2->value;

        // Move to the next node in both lists
        current1 = current1->next;
        current2 = current2->next;
    }

    return list1;  // Return the updated first list
}
```

### Duplicate

```c
// Duplicate linked list, return the new one
Node *duplicate(Node *list) {
    if (list == NULL)
        return NULL;

    Node *current = list;
    Node *new_list = NULL;
    Node *tail = NULL;

    while (current != NULL) {
        Node *new_node = calloc(1, sizeof(Node));
        if (new_node == NULL) {
            // Handle memory allocation failure
            return NULL;
        }

        // Copy value and set next pointer
        new_node->value = current->value;
        new_node->next = NULL;

        if (new_list == NULL) {
            // Set the new node as the head of the new list
            new_list = new_node;
            tail = new_node;
        } else {
            // Append the new node to the new list
            tail->next = new_node;
            tail = new_node;
        }

        current = current->next;
    }

    return new_list;
}
```
