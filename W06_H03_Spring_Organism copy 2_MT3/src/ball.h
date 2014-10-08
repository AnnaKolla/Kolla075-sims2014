//
//  ball.h
//  Spring_Organism
//
//  Created by Annelie Koller on 10/7/14.
//
//

#ifndef __Spring_Organism__ball__
#define __Spring_Organism__ball__

#include "ofMain.h"
#include "SpringJoint.h"

class ball {
    
public:
    
    void update();
    void draw();
    
    
    ball(float x, float y, int r);
    
    //vars
    
    ofPoint pos;
    float x;
    float y;
    
    float vx;
    float vy;
    float gravity;
    float friction;
    
    void	xenoToPoint(float catchB);
    void    interpolateByPct(float myPct);
    
    float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
    
    float		xenoR;
    float       radB;
    
    int maxv;
    
    int r;
    int g;
    int b;
    
    
    
private:
    
    
};

#endif /* defined(__Spring_Organism__ball__) */
