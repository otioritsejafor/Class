// File: <image.cpp>
// This file contains implementation for image class
//
// ------------------------------------------------------------------
// Class: CS 215                              Instructor: Dr.Deborah Hwang
// Assignment: Project 3                      Date assigned: 10/13/2017
// Programmer: Oti Oritsejafor                Date completed: 10/23/2017

//  Copyright © 2017 Oti Oritsejafor. All rights reserved.


#include "image.h"
#include <iostream>
#include <algorithm>


using namespace std;

PGMImage::PGMImage () {
  ht = 0;
  wd = 0;
  max = 0;
  image = nullptr;
}

// Copy constructor that creates a copy of given image
PGMImage::PGMImage(const PGMImage & original) {
  wd = original.wd;
  ht = original.ht;
  max = original.max;

  image = new int[wd * ht]; // separate space must be allocated for the copy
  for(int i=0; i< ht; i++) {
    for(int j=0; j<wd; j++) {
      at(i,j)= original.at(i,j);
    }
  }
}

// Destructor
PGMImage::~PGMImage() {
  delete [] image;  // Free space used on the heap
}

// Overloaded assingment operator with swap
PGMImage &PGMImage::operator=(const PGMImage &original) {  
  PGMImage copy(original);
  swap(ht, copy.ht);
  swap (wd, copy.wd);
  swap (max, copy.max);
  swap(image, copy.image);

  return *this;
}

// Checks if the image is empty
bool PGMImage::empty() const {
  return (ht * wd == 0);
}
// Returns height of image
int PGMImage::height() const{
  return ht;
}

// Returns width of image
int PGMImage::width() const{
  return wd;
}

// Returns maximum pixel value
int PGMImage::max_value() const {
  return max;
}

// Rotates image 90 degrees clockwise
PGMImage PGMImage::rotate_right() const
{
  PGMImage new_image;
  new_image.image = new int[wd*ht];
  new_image.ht = wd;    // the height changes to the width and vice versa, to get right proportions
  new_image.wd = ht;
  new_image.max = max;
  for(int i=0; i < wd; i++) {
    for(int j=0; j < ht; j++) {
      new_image.at(i,j) = at(ht-1-j, i);
    }
  }   
  return new_image;
}

// Rotates image 90 degrees counter-clockwise
PGMImage PGMImage::rotate_left() const
{
  PGMImage new_image;
  new_image.image = new int[wd*ht];
  new_image.ht = wd;
  new_image.wd = ht;
  new_image.max = max;
  for(int i=0; i < wd; i++) {
    for(int j=0; j < ht; j++) {
      new_image.at(i,j) = at(j, wd-1-i);
    }
  }
    
  return new_image;
}

// Flips the image vertically
PGMImage PGMImage::flip_vertical() const
{
  PGMImage new_image;
  new_image.image = new int[wd*ht];
  new_image.ht = ht;
  new_image.wd = wd;
  new_image.max = max;
    
  for (int i = 0; i < ht; i++) {
    for (int j = 0; j < wd; j++) {
      new_image.at(i,j)= at(i,wd-1-j);
    }
  }
    
  return new_image;
}

// Flips the image horizontally
PGMImage PGMImage::flip_horizontal() const {
    
  PGMImage new_image;
  new_image.image = new int[wd*ht];
  new_image.ht = ht;
  new_image.wd = wd;
  new_image.max = max;
    
  for(int i=0; i< ht; i++) {
    for(int j=0; j<wd; j++) {
      new_image.at(i,j)= at(ht-1-i, j);
    }
  }
    
  return new_image;
}

// Returns an inverse of the image
PGMImage PGMImage::invert() const
{
  PGMImage new_image;
  new_image.image = new int[wd*ht];
  new_image.ht = ht;
  new_image.wd = wd;
  new_image.max = max;
    
  for(int i=0; i< ht; i++) {
    for(int j=0; j<wd; j++) {
      new_image.at(i,j)= max- at(i,j);
    }
  }

  return new_image;
    
}

// Loads the image from a pgm file
void PGMImage::load(std::ifstream & in_file)
{
  int i = 0;
  int number;
  string ispgm;
    
  if (in_file.is_open())
    {
      getline(in_file, ispgm);
      if(ispgm!="P2") {
	throw runtime_error("File is not a PGM image file");
      }
        
      in_file >> wd;
      in_file >> ht;
      in_file >> max;
      image = new int [wd * ht];        
      while(in_file >> number) {
	image[i] = number;
	i++;
      }
        
    }
  else {
    cout << "Could not open file: " << endl;
  }
    
}

// Writes image into pgm file
void PGMImage::write(std::ofstream & out_file)
{
  out_file << "P2" << endl;
  out_file << wd << " " << ht << endl;
  out_file << max << endl;
    
  for(int i=0; i < ht; i++) {
    for(int j=0; j < wd; j++) {
      out_file << setw(4) << at(i, j);
    }
    out_file << endl;
  }
 
}
