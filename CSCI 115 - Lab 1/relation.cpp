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

List::List()
{
    head = NULL;
}

bool List::lookup(int e)
{
    Node* p = head;
    if (head == NULL)
    {
        return false;
    }
    
    while (p->next != NULL)
    {
        if (p->value == e)
        {
            return true;
        }
        p = p->next;
    }
    
    if (p->value == e)
    {
        return true;
    }
    
    return false;
}

void List::cons(int e)
{
    Node* nn = new Node();
    nn->value = e;
    
    if (this->head == NULL)
    {
        this->head = nn;
        nn->next = NULL;
        return;
    }
    
    nn->next = this->head;
    this->head = nn;
    
    return;
}

Relation::Relation(int e)
{
    succs = (List*) malloc (e);
    
    for (int i = 0; i < (e - 1) ; i++)
    {
        succs[i] = *new List();
    }
    
    this->nelts = e;
    this->npairs = 0;

}

void Relation::insert_pair(int e1, int e2)
{
    
    if ((e1 >= (this->num_elts())) || (e2 >= (this->num_elts())))
    {
        cout << "Error: non-existent element(s)";
        cout << endl << endl;
        return;
    }
    
    if (succs[e1].lookup(e2))
    {
        return;
    }
    
    succs[e1].cons(e2);
    
    (this->npairs)++;
    
    return;
}

void Relation::list_pairs()
{
    Node* p;
    
    cout << "Pairs: ";
    
    for (int i = 0; i < (num_elts()); i++)
    {
        p = succs[i].head;
        
        if (p == NULL)
        {
            continue;
        }
        
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


void Relation::list_succs(int e)
{
    if (e >= (this->num_elts()))
    {
        cout << "Error: non-existent element(s)";
        cout << endl << endl;
    }
    
    Node* p = succs[e].head;
    
    cout << "Successors: " ;
    
    if (p == NULL)
    {
        cout << endl << endl;
        return;
    }
    
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

void Relation::list_preds(int e)
{
    if (e >= (this->num_elts()))
    {
        cout << "Error: non-existent element(s)";
        cout << endl << endl;
    }
    
    Node* p;
    
    cout << "Predecessors: ";
    
    for (int i = 0; i < (num_elts()); i++)
    {
        p = succs[i].head;
        
        if (p == NULL)
        {
            continue;
        }
        
        while (p->next != NULL)
        {
            if (p->value == e)
            {
                cout << i << " ";
            }
            p = p->next;
        }
        
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

int Relation::num_elts()
{
    return (this->nelts);
}

int Relation::num_pairs()
{
    return (this->npairs);
}

int Relation::num_succs(int e)
{
    Node* p = succs[e].head;
    
    int count = 0;
    
    if (p == NULL)
    {
        return 0;
    }
    
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    
    if (p->next == NULL)
    {
        count++;
    }
    
    return count;
}
