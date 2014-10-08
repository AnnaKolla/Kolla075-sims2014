//
//  SpringJoint.cpp
//  Spring_Organism
//
//  Created by Annelie Koller on 10/5/14.
//
//

#include "SpringJoint.h"

void SpringJoint::applyForce(ofVec2f force) {
    acc += force;
    
    radC = 40;
    rad = 10;
}

void SpringJoint::update() {
    
    
    vel += acc;
    pos += vel;
    
    vel *= 0.96;
    
    acc.set(0);
 
}

void SpringJoint::draw() {
    
    ofEnableAlphaBlending();
    
    ofSetColor(255,0,0);
    ofCircle( pos, rad );
    
    ofSetColor(250,20,157,50);
   
    ofCircle(pos, radC);
    
 
    
   
}