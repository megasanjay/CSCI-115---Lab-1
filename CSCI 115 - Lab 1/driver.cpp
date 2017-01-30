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

int main(int argc, const char * argv[])
{
    int input = 0;
    int menuinput = 0;
    int e, e1, e2;
    
    string menu = "Menu: \n1 - Print relation information \n2 - Insert a pair into the relation \n3 - List all pairs in the relation \n4 - List all successors of a particular element \n5 - List all predecessors of a particular element \n6 - Quit \n";
    
    while (input <= 0 )
    {
        cout << "Enter the number of elements in the relation: ";
        
        cin.clear();
        cin >> input;
        
        if (input < 1)
        {
            cout << "Error: number of elements must be positive";
            cout << endl << endl;
        }
    }
    
    Relation* nr = new Relation(input);
    
    while (menuinput != 6)
    {
        cout << menu << endl << "Choose a function (1 - 6): ";
        
        cin.clear();
        cin >> menuinput;
        
        cout << endl;
        
        if (menuinput == 1)
        {
            cout << "Relation has " << nr->num_elts() << " elements and " << nr->num_pairs() << " pairs";
            cout << endl << endl;
            continue;
        }
        if (menuinput == 2)
        {
            cout << "Enter two elements seperated by a space: " ;
            
            cin.clear();
            cin >> e1;
            
            cin.clear();
            cin >> e2;
            
            cout << endl;
            
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
            
            cout << endl;
            
            nr->list_succs(e);
            
            continue;
        }
        if (menuinput == 5)
        {
            cout << "Enter the element to list all of the predecessors of: ";
            
            cin.clear();
            cin >> e;
            
            cout << endl;
        
            nr->list_preds(e);
            
            continue;
        }
        if (menuinput == 6)
        {
            cout << endl << endl;
            
            break;
        }
    }
        
    return 0;
}
