#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "structs.h"
#include "util.h"

// Function prototypes
NODE * listInsert(LIST *, double);
NODE * listAppend(LIST *, double);
NODE * listSearch(LIST *, double);
NODE * listDelete(LIST *, double);

// Function implementations
NODE * listInsert(LIST *list, double key) {
    // Create a new node
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        std::cerr << "Error: cannot allocate memory\n";
        exit(1);
    }
    
    newNode->key = key;
    newNode->next = list->head;
    list->head = newNode;
    
    // If the list was empty, set tail to the new node
    if (list->tail == NULL) {
        list->tail = newNode;
    }
    
    // Print message to stdout
    std::cout << "Node with key " << key << " inserted\n";
    
    return newNode;
}

NODE * listAppend(LIST *list, double key) {
    // Create a new node
    NODE *newNode = (NODE *)malloc(sizeof(NODE));
    if (!newNode) {
        std::cerr << "Error: cannot allocate memory\n";
        exit(1);
    }
    
    newNode->key = key;
    newNode->next = NULL;
    
    if (list->tail != NULL) {
        list->tail->next = newNode;
    }
    
    list->tail = newNode;
    
    // If the list was empty, set head to the new node
    if (list->head == NULL) {
        list->head = newNode;
    }
    
    // Print message to stdout
    std::cout << "Node with key " << key << " appended\n";
    
    return newNode;
}

NODE * listSearch(LIST *list, double key) {
    NODE *current = list->head;
    
    while (current != NULL) {
        if (current->key == key) {
            // Print message to stdout
            std::cout << "Query " << key << " FOUND in list\n";
            return current;
        }
        current = current->next;
    }
    
    // If not found
    std::cout << "Query " << key << " NOT FOUND in list\n";
    return NULL;
}

NODE * listDelete(LIST *list, double key) {
    NODE *current = list->head;
    NODE *prev = NULL;
    
    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) { // Node to be deleted is the head
                list->head = current->next;
                if (list->tail == current) {
                    list->tail = NULL; // List is now empty
                }
            } else {
                prev->next = current->next;
                if (list->tail == current) {
                    list->tail = prev; // Update tail if last node is deleted
                }
            }
            
            // Free the memory for the node
            free(current);
            
            // Print message to stdout
            std::cout << "Node with key " << key << " deleted\n";
            return prev;
        }
        prev = current;
        current = current->next;
    }
    
    // If not found
    std::cout << "Node with key " << key << " not found\n";
    return NULL;
}
// Serene Akhtar
// Asu ID: 1224434328
