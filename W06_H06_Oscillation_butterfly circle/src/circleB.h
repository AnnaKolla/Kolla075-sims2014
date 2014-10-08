//
//  circle.h
//  Week2_exercise_pendulum
//
//  Created by Annelie Koller on 10/8/14.
//
//

#ifndef __Week2_exercise_pendulum__circle__
#define __Week2_exercise_pendulum__circle__

#include "ofMain.h"


class circleB {
    
public:
    
    void update();
    void draw();

    
    circleB(float CentreX, float CentreY);
    
    //int id;
    float angnoise, radiusnoise;
    float widnoise, heinoise;
    float angle = 0;
    float radius = 50;
    float CentreX;
    float CentreY;
    float rad;
    float strokeCol = 254;
    float r, g, b;
    float lastX = 9999;
    float lastY, lastAng;
    float lastOuterX, lastOuterY;
    
    float wid ;
   
    float x1 ;
    float y1 ;
    
    float outerRadius;
    float outerX;
    float outerY ;
   
    
private:
    
    
};


#endif /* defined(__Week2_exercise_pendulum__circle__) */
