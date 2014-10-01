//
//  Path.cpp
//  myFlock_01
//
//  Created by Annelie Koller on 10/1/14.
//
//

#include "path.h"

path::path() {


    start.set(0,ofGetHeight()/3);
    end.set(ofGetWidth(), ofGetHeight()/2);

}

void path:: draw(){
    

   
    ofSetLineWidth(1);

    ofLine(start.x,start.y,end.x,end.y);
    
    ofSetLineWidth(2);
    
    ofLine(start.x,start.y,end.x,end.y);
  
    
    
}