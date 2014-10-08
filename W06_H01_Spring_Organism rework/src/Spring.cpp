//
//  Spring.cpp
//  Spring_Organism
//
//  Created by Annelie Koller on 10/5/14.
//
//

#include "spring.h"

//---------------------------------------------------------------------
spring::spring(){
    particleA = NULL;
    particleB = NULL;
}

void spring::set( particle *_particleA, particle *_particleB, float _springiness, float _distance ) {
    particleA = _particleA;
    particleB = _particleB;
    springiness = _springiness;
    distance = _distance;
}


//---------------------------------------------------------------------
void spring::update(){
    
    if ((particleA == NULL) || (particleB == NULL)){
        return;
    }
    
    ofVec2f pta = particleA->pos;
    ofVec2f ptb = particleB->pos;
    
    ofVec2f force = pta - ptb;
    
    float theirDistance = force.length();
    float springForce = (springiness * (distance - theirDistance));
   

    ofVec2f frcToAdd = force.normalized() * springForce;
    
    particleA->addForce(frcToAdd.x, frcToAdd.y);
    particleB->addForce(-frcToAdd.x, -frcToAdd.y);
}


//---------------------------------------------------------------------
void spring::draw(){
    
    if ((particleA == NULL) || (particleB == NULL)){
        return;
    }
    
    ofLine(particleA->pos.x, particleA->pos.y, particleB->pos.x, particleB->pos.y);
}