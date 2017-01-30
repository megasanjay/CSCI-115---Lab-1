//
//  main.cpp
//  CSCI 115 - Lab 1
//
//  Created by Sanjay Soundarajan on 1/27/17.
//  Copyright © 2017 Sanjay Soundarajan. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include "relation.h"

using namespace std;

List::List()    // List constructor
{
    head = NULL;    // Set head to NULL
    length = 0;     // Set length of list to 0
}

bool List::lookup(int e)    // lookup function for the List class
{
    Node* p = head;
    
    // Return false if the list is empty
    if (head == NULL)
    {
        return false;
    }
    
    // If the value exists in the list, return true
    while (p->next != NULL)
    {
        if (p->value == e)
        {
            return true;
        }
        p = p->next;
    }
    
    // If the last value in the node = searched value, return true
    if (p->value == e)
    {
        return true;
    }
    
    return false;  // If the value is not in the list, return false
}

void List::cons(int e)  // cons function to add pairs to list
{
    // Create new node and add value to node
    Node* nn = new Node();
    nn->value = e;
    
    // If the list is empty, add node to list and update head to point to new node
    if (this->head == NULL)
    {
        this->head = nn;
        nn->next = NULL;
        (this->length)++; // Update list length
        return;
    }
    
    // if the list already has node, update head to point to new node
    nn->next = this->head;
    this->head = nn;
    
    (this->length)++; // Update list length
    
    return;
}

Relation::Relation(int e)   // Relation() constructor
{
    succs = (List*) malloc (e); // reallocate memory to succs array inorder to update size. The new size of the error is 'e'
    
    if (e == 1)     // If only one node is needed, create a single empty list
    {
        succs[0] = *new List();
    }
    
    // Create an empty list for each slot of the arrya
    for (int i = 0; i < (e - 1) ; i++)
    {
        succs[i] = *new List();
    }
    
    // update relation element count and reset pair count
    this->nelts = e;
    this->npairs = 0;

}

void Relation::insert_pair(int e1, int e2)  // Insert pair function for the relation class
{
    // If the input elements are out of bounds, return error message
    if ((e1 < 0) || (e2 < 0))
    {
        cout << "Error: non-existent element(s)";
        cout << endl << endl;
        return;
    }
    
    // the input elements are out of bounds, return error message
    if ((e1 >= (this->num_elts())) || (e2 >= (this->num_elts())))
    {
        cout << "Error: non-existent element(s)";
        cout << endl << endl;
        return;
    }
    
    // If the pair already exists in the realtion, ignore it
    if (succs[e1].lookup(e2))
    {
        return;
    }
    
    succs[e1].cons(e2); // add pair to list
    
    (this->npairs)++;   // Update pair count
    
    return;
}

void Relation::list_pairs()     // list pairs function for the realtion
{
    Node* p;
    
    cout << "Pairs: ";
    
    // Cycle through elements listing out the pairs for each relation element
    for (int i = 0; i < (num_elts()); i++)
    {
        if (succs[i].length == 0)   // If no pairs exist, move onto the next element
        {
            continue;
        }
        
        p = succs[i].head;
        
        // Print out the pairs for the list
        while (p->next != NULL)
        {
            cout << '(' << i << ',' << p->value << ") ";
            p  = p->next;
        }
        
        if (p->next == NULL)
        {
            cout << '(' << i << ',' << p->value << ") ";
        }
    }
    
    cout << endl << endl;
    
    return;
}


void Relation::list_succs(int e)    // list successors to a requested element
{
    // If the input elements are out of bounds, return error message
    if ((e >= (this->num_elts())) || (e < 0))
    {
        cout << "Error: non-existent element(s)";
        cout << endl << endl;
    }
    
    Node* p = succs[e].head;
    
    cout << "Successors: " ;
    
    if (p == NULL)      // If there are no successors, return
    {
        cout << endl << endl;
        return;
    }
    
    // Print out the successors for an element
    while (p->next != NULL)
    {
        cout << p->value << " ";
        p = p->next;
    }
    
    if (p->next == NULL)
    {
        cout << p->value << " ";
    }
    
    cout << endl << endl;
    
    return;
}

void Relation::list_preds(int e)    // list successors to a requested element
{
    // If the input elements are out of bounds, return error message
    if (e >= (this->num_elts()))
    {
        cout << "Error: non-existent element(s)";
        cout << endl << endl;
    }
    
    Node* p;
    
    cout << "Predecessors: ";
    
    // Loop through each pair. Search for the element requested and print the element value
    for (int i = 0; i < (num_elts()); i++)
    {
        p = succs[i].head;
        
        if (p == NULL)
        {
            continue;
        }
        
        // loop through list to see if the element requested exists
        while (p->next != NULL)
        {
            if (p->value == e)
            {
                cout << i << " ";
                break;
            }
            p = p->next;
        }
        
        // If the last value in the list is the requesdted element, print predecessor
        if (p->next == NULL)
        {
            if (p->value == e)
            {
                cout << i << " ";
            }
        }
    }
    
    cout << endl << endl;
    
    return;
}

int Relation::num_elts()    // method to access the private member nelts(number of elements)
{
    return (this->nelts);
}

int Relation::num_pairs()   // method to access the private member npairs(number of pairs)
{
    return (this->npairs);
}

int Relation::num_succs(int e)  // method to print nmber of elements in a list(succesddors to an element in the relation)
{
    return (succs[e].length);
    
}
