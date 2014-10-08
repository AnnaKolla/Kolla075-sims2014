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

#include "particle.h"

class spring {
    
public:
    
    spring();
    
    particle * particleA;
    particle * particleB;
    
    float distance;
    float springiness;	 // this is the k, springiness constant
    
    void update();
    void draw();
    
    float origDistance;
    
    
    
};

#endif /* defined(__Spring_Organism__Spring__) */
