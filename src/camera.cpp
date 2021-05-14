#include "camera.h"


Camera::Camera(const string &name){
    mName = name; 
};

Camera::~Camera(){
    cout<< "destroy " << mName<<endl;
}

void Camera::print(){
    cout<< "camera name :" << mName << endl;
};