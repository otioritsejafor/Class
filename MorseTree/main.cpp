// File: morse.cpp
// This file contains demonstration for MorseTree class
//
// ------------------------------------------------------------------
// Class: CS 215                              Instructor: Dr.Deborah Hwang
// Assignment: Project 7                      Date assigned: 12/27/2017
// Programmer: Oti Oritsejafor                Date completed: 12/04/2017

//  Copyright © 2017 Oti Oritsejafor. All rights reserved.

#include <iostream>
#include "morse.hpp"
using namespace std;

void print_menu();

int main(int argc, const char * argv[]) {
    using namespace std;
    /*
    // 1. Check for correct number of arguments
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << "<input file>" << endl;
        exit(1);
    }
    // 2. Open files
    */
    string filename;
    //cout << "Enter file name: ";
    ifstream inFile (argv[1]); // first argument is input file name
    //cin >> filename;
    inFile.open("samplecodefile.dat");
    // 3. Check for successful opens
    if (!inFile)
    {
        cout << "Error opening input file " << argv[1] << endl;
        exit(1);
    }
    
    MorseTree tree(inFile);
    tree.write(std::cout);
    
    char choice;
    ifstream in_file;
    ofstream out_file;
    string input_file_name;
    string output_file_name;
    
    do
    {
        print_menu();
        cout << "Enter your command: ";
        cin >> choice;
        choice = toupper(choice);
        switch (choice)
        {
                
            case 'E':
                cout << "Enter the name of a plain text message file: ";
                cin >> input_file_name;
                in_file.open(input_file_name);
                tree.encode(in_file, std::cout);
                in_file.close();
                break;
                
            case 'D':
                cout << "Enter name of an encoded message file: ";
                cin >> input_file_name;
                in_file.open(input_file_name);
                tree.decode(in_file, std::cout);
                in_file.close();
                break;
                
            case 'Q':
                cout << "Merry christmas and have a happy holidays!" << endl;
                
            default:
                cout << "osas" << endl;
                break;
                
        }
    }while((choice != 'Q'));
    
    
    return 0;
}

void print_menu() {
    cout << "Choose from the following commands" << endl;
    cout << "    E - Encode the message" <<  endl;
    cout << "    D - Decode the message" <<  endl;
    cout << "    Q - Decode the message" <<  endl;
    
}
