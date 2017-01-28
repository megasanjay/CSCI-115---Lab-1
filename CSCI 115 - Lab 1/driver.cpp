//
//  driver.cpp
//  CSCI 115 - Lab 1
//
//  Created by Sanjay Soundarajan on 1/27/17.
//  Copyright © 2017 Sanjay Soundarajan. All rights reserved.
//

#include <iostream>
#include <limits>
#include "relation.h"

using namespace std;
//to be done later
bool validate(char input)
{
    if (!isdigit(input))
    {
        cout << "Only numbers are allowed";
        return false;
    }
    return true;
}

int main(int argc, const char * argv[])
{
    int input;
    int menuinput  = 0;
    int e, e1, e2;
    
    string menu = "Menu: \n1 - print relation information \n2 - insert a pair into the relation \n3 - list all pairs in the relation \n4 - list all successors of a particular element \n5 - list all predecessors of a particular element \n6 - quit \n";
    //  bool flag = true;
    
   /* while (flag)
    {
        cout << "Enter the number of elements in the relation: ";
        cin >> input;
        
        validate(input);
    }*/
   
    cout << "Enter the number of elements in the relation: ";
    //cout << menu;
    cin >> input;
    
    Relation* nr = new Relation(input);
    
    while (menuinput != 6)
    {
        cout << menu << endl << "Choose a function (1 - 6): ";
        cin >> menuinput;
        
        if (menuinput == 1)
        {
            cout << "Relation has " << nr->num_elts() << " elements and " << nr->num_pairs() << " pairs";
            continue;
        }
        if (menuinput == 2)
        {
            cout << "Enter two elements seperated by a space: " ;
            cin.clear();
            cin >> e1;
            if (e1 >= (nr->num_elts()))
            {
                cout << "Error: non-existent element(s)" << endl;
                continue;
            }
            cin.clear();
            cin >> e2;
            if (e2 >= (nr->num_elts()))
            {
                cout << "Error: non-existent element(s)" << endl;
                continue;
            }
            nr->insert_pair(e1, e2);
            continue;
        }
        if (menuinput == 3)
        {
            nr->list_pairs();
        }
        if (menuinput == 4)
        {
            cout << "Enter the element to list all of the successors of: ";
            cin.clear();
            cin >>  e;
            if (e >= (nr->num_elts()))
            {
                cout << "Error: non-existent element(s)" << endl;
                continue;
            }
            nr->list_succs(e);
            continue;
        }
        if (menuinput == 5)
        {
            cout << "Enter the element to list all of the predecessors of: ";
            cin.clear();
            cin >> e;
            if (e >= (nr->num_elts()))
            {
                cout << "Error: non-existent element(s)" << endl;
                continue;
            }
            nr->list_preds(e);
            continue;
        }
        if (menuinput == 6)
        {
            break;
        }
    }
        
    return 0;
}
