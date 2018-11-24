// File: <image_manipulator.cpp>
// This file contains implementation for image class
//
// ------------------------------------------------------------------
// Class: CS 215                              Instructor: Dr.Deborah Hwang
// Assignment: Project 3                      Date assigned: 10/13/2017
// Programmer: Oti Oritsejafor                Date completed: 10/25/2017

//  Copyright © 2017 Oti Oritsejafor. All rights reserved.

#include <iostream>
#include "image.h"
using namespace std;

void print_menu();

int main(int argc, const char * argv[]) {
    
  
  char choice;
  ifstream in_file;
  ofstream out_file;
  string input_file_name;
  string output_file_name;
  PGMImage current;
  PGMImage rotated;
    do
      {
        print_menu();
        cout << "Enter your command: ";
        cin >> choice;
        choice = toupper(choice);
        switch (choice)
	  {
	  case 'L':
	    try {
	      cout << "Enter name of image file to load into current image: ";
	      cin >> input_file_name;
	      in_file.open(input_file_name);
	      current.load(in_file);cout<<current.width()<<endl;
	    }
	    catch(const runtime_error &re) {    // The thrown exception object
	      // Print out its message
	      cout << re.what() << " Try again!" << endl;
	    }
	    break;
	  case 'A':
	    cout << "Creating rotated image" << endl;
	    current =  current.rotate_left();
	    break;
	  case 'B':
	    cout << "Creating rotated image" << endl;
	    current = current.rotate_right();
	    break;
	  case 'C':
	    cout << "Creating a flipped image" << endl;
	    current = current.flip_horizontal();
	    break;
	  case 'D':
	    cout << "Creating a flipped image" << endl;
	    current = current.flip_vertical();
	    break;
	  case 'E':
	    cout << "Creating an inverted image" << endl;
	    current = current.invert();
	    break;
	  case 'W':
	    cout << "Enter name of file to write new image: ";
	    cin >> output_file_name;
	    out_file.open(output_file_name);
	    current.write(out_file);
	    out_file.close();
	    break;
	  default:
	    cout << "osas" << endl;
	    break;
                
	  }
      }while((choice != 'Q'));
    
    
    return 0;
}

void print_menu() {
  cout << "Choose from the following commands" << endl;
  cout << "    L - load current image from file" <<  endl;
  cout << "    A - Create a new image rotated 90 degrees left" << endl;
  cout << "    B - Create a new image rotated 90 degrees right" << endl;
  cout << "    C - Create a new image flipped along horizontal axis" << endl;
  cout << "    D - Create a new image flipped along vertical axis" << endl;
  cout << "    E - Create a new inverted image" << endl;
  cout << "    W - Write new image to file" << endl;
  cout << "    Q - Quit the program" << endl;
    
}
