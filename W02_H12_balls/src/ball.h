//
//  ball.h
//  week2_balls
//
//  Created by Annelie Koller on 9/28/14.
//
//

#ifndef __week2_balls__ball__
#define __week2_balls__ball__
#include "ofMain.h"

#include <iostream>


class Ball {
    
public:
    
    void update();
    void draw();
    
    
    Ball(float x, float y, int r);
    
    //vars
    float x;
    float y;
    int rad;
    float vx;
    float vy;
    float gravity;
    float friction;
 
    int maxv;
    
    int r;
    int g;
    int b;
    
private:
    
    
};

#endif /* defined(__week2_balls__ball__) */
