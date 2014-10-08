//
//  SpringJoint.h
//  Spring_Organism
//
//  Created by Annelie Koller on 10/5/14.
//
//

#ifndef __Spring_Organism__SpringJoint__
#define __Spring_Organism__SpringJoint__

#pragma once

#include "ofMain.h"

class SpringJoint {
public:
    void update();
    void draw();
    void applyForce( ofVec2f force );
    
    ofVec2f pos, vel, acc;
    float radC;
    float rad;
};

#endif /* defined(__Spring_Organism__SpringJoint__) */
