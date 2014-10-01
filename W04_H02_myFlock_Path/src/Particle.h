//
//  Particle.h
//  myFlock_01
//
//  Created by Annelie Koller on 9/30/14.
//
//

#ifndef __myFlock_01__Particle__
#define __myFlock_01__Particle__

#include <iostream>
#include "ofMain.h"

class Particle {
    
    
public:
    
    Particle();
    
    void setInit(ofPoint _pos, ofPoint _vel = ofPoint(0,0));
    
    ofPoint getPosition();
    float   getRadius();
    
  
    void addForce(ofPoint _force);
    
    void addRepulsionForce(ofPoint _pos, float _rad, float _scale);
    void addAttractionForce(ofPoint _pos, float _rad, float _scale);
    void addClockwiseForce( ofPoint _pos, float _rad, float _scale);
    void addCounterClockwiseForce( ofPoint _pos, float _rad, float _scale);
    
    void seek( ofPoint dest );
    
    void update();
    void draw();
    
    ofColor color;
    

    ofPoint pos;
    ofPoint vel;
    ofPoint acc;
    ofPoint predict;
    ofPoint maxForce;
    ofPoint maxSpeed;
    
    float radius;
    float damp;
  
};


#endif /* defined(__myFlock_01__Particle__) */
