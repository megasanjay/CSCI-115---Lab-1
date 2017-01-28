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

List *Relations;

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



Relation::Relation(int e)
{
    
    succs = (List*) malloc (e);
    
    for (int i = 0; i < e-1; i++)
    {
        succs[i] = *new List();
    }
    
    this->nelts = e;
    this->npairs = 0;
    
    /* Test bench
    succs[0] = *new List();
    succs[0].head->value = 0;
    cout << &(succs[0]) << endl;
    succs[1] = *new List();
    cout << &(succs[1])<< endl;
    succs[1].head->value = 1;
    succs[2] = *new List();
    cout << &(succs[2])<< endl;
    succs[2].head->value = 2;
    cout << (succs[0]).head->value<< endl;
    cout << (succs[1]).head->value<< endl;
    cout << (succs[2]).head->value<< endl;
    cout.flush();
    cin.ignore();
    //succs[0].cons(e)
    
    /*Relations = new List::List();
    Node* headnode = new Node();
    Node* nn = new Node();
    
    Relations->head = headnode;
    headnode->value = 0;
    
    for(int i = 1; i < e; i++)
    {
        if (i == 1)
        {
            nn->value = i;
            headnode->next = nn;
            continue;
        }
        nn->next = new Node();
        nn = nn->next;
        nn->value = i;
        nn->next = NULL;
    }
    
    /*nn = headnode;
    while (nn->next != NULL)
    {
        cout << nn->value << endl;
        nn = nn->next;
    }
    
    cout << nn->value << endl;
    
    cin.clear();
    
    Node* nn = new Node();
    nn = Relations->head;
    for (int i = 1; i < data; i++)
    {
        nn = new Node();
        nn->value = i;
        nn->next = NULL;
    }*/
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

void Relation::insert_pair(int e1, int e2)
{
    //Node* nn = new Node();
    
    //succs[e1].cons(e2);
    
    if (succs[e1].lookup(e2))
    {
        return;
    }
    
    succs[e1].cons(e2);
    
    this->npairs++;
    /*
    if (succs[e1].head == NULL)
    {
        succs[e1].head = nn;
        nn->next = NULL;
        this->npairs++;
        return;
    }
    
    nn->next = succs[e1].head;
    succs[e1].head = nn;
    
    this->npairs++;
    
    return;*/
}

void Relation::list_pairs()
{
    //nn[2] = NULL;
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
            cout << '(' << i << ',' << p->value << ')' << endl;
        }
    }
    
    return;
}


void Relation::list_succs(int e)
{
    Node* p = succs[e].head;
    
    cout << "Successors: " ;
    
    if (p == NULL)
    {
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
    
    return;
    
}

void Relation::list_preds(int e)
{
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
    
    cout << endl;
    
    return;
}

int Relation::num_elts()
{
    return this->nelts;
}

int Relation::num_pairs()
{
    return this->npairs;
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


//int main(int argc, const char * argv[])
//{
  //  return 0;
//}
