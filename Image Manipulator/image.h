// File: <image.h>
// This file contains declaration of image class variables and fuctions
//
// ------------------------------------------------------------------
// Class: CS 215                              Instructor: Dr.Deborah Hwang
// Assignment: Project 3                      Date assigned: 10/13/2017
// Programmer: Oti Oritsejafor                Date completed: 10/23/2017

//  Copyright © 2017 Oti Oritsejafor. All rights reserved.

#ifndef image_h
#define image_h

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

class PGMImage {
 public:
    
  PGMImage();
  PGMImage(const PGMImage &original);
  ~PGMImage();
  PGMImage &operator=(const PGMImage &original);
    
  // Accessor functions
  bool empty() const;
  int width() const;
  int height() const;
  int max_value() const;
  int& at(int row, int col) {
    int index = (row * wd) + col;
    return image[index];
  }
  const int &at(int row, int col) const {
    int index = (row * wd) + col;
    return image[index];
  }
    
  // Image rotation functions
  PGMImage rotate_right() const;
  PGMImage rotate_left() const;
  PGMImage flip_horizontal() const;
  PGMImage flip_vertical() const;
  PGMImage invert() const;

  // Load and write
  void load(std::ifstream & in_file);
  void  write(std::ofstream & out_file);

    
 private:
  int wd;
  int ht;
  int max;
  int *image;
    
    
    
};



#endif /* image_h */
