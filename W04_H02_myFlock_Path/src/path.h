//
//  Path.h
//  myFlock_01
//
//  Created by Annelie Koller on 10/1/14.
//
//

#ifndef __myFlock_01__Path__
#define __myFlock_01__Path__

#include <iostream>

#include "ofMain.h"


class path {
    
    
  
public:
    
    
    path();
    
   
   void draw();
    
    
    ofPoint start;
    ofPoint end;
    float radius;
    ofColor color;
    

    
};

#endif /* defined(__myFlock_01__Path__) */
