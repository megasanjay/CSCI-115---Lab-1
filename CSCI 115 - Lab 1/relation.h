//
//  relation.h
//  CSCI 115 - Lab 1
//
//  Created by Sanjay Soundarajan on 1/27/17.
//  Copyright © 2017 Sanjay Soundarajan. All rights reserved.
//

#ifndef relation_h
#define relation_h

// One node of a linked list
struct Node {
    int value; // value stored in node
    Node *next; // pointer to next node (or NULL)
};
// Linked list with cached length
struct List {
    Node *head; // pointer to first node (or NULL)
    int length; // number of nodes in list
    List(); // default constructor
    bool lookup(int e); // is e in the list?
    void cons(int e); // add e to beginning of list
};
// Main class
class Relation {
private:
    int nelts; // number of elements
    int npairs; // number of pairs
    List *succs; // array of successor lists
public:
    Relation(int n); // constructor (assumes n>0)
    int num_elts(); // number of elements
    int num_pairs(); // number of pairs
    int num_succs(int e); // number of successors of e
    void insert_pair(int e1, int e2); // insert pair (e1,e2)
    void list_pairs(); // list all pairs in the relation
    void list_succs(int e); // list all successors of e
    void list_preds(int e); // list all predecessors of e
};

#endif /* relation_h */
