//
//  Spring.h
//  Spring_Organism
//
//  Created by Annelie Koller on 10/5/14.
//
//

#ifndef __Spring_Organism__Spring__
#define __Spring_Organism__Spring__

#pragma once

#include "ofMain.h"
#include "SpringJoint.h"

class Spring {
    
public:
    
    void set( SpringJoint *_s1, SpringJoint *_s2, float _k, float _restLength );
    void applyForce( ofVec2f force );
    void update();
    void draw();
    
    void connect( Spring *s );
    
    SpringJoint *s1, *s2;
    float   k, restLength;
};

#endif /* defined(__Spring_Organism__Spring__) */
