#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Camera{

public: 
   Camera(const string &name);
   ~Camera();
   void print();
   string mName;
};

#endif