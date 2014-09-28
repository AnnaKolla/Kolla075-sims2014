//
//  ball.cpp
//  week2_balls
//
//  Created by Annelie Koller on 9/28/14.
//
//

#include "ball.h"
#include "Ball.h"
#include "testApp.h"

Ball::Ball(float _x, float _y, int _rad)

{
    x = _x;
    y = _y;
    rad = _rad;
    maxv = 20; // max velocity
    vx = ofRandom(maxv * -1, maxv);
    vy = ofRandom(0, maxv);
    gravity = 0.03;
    friction = -0.8;
    
    r, g, b = ofRandom(0, 255); // ball border color
  
    
}

void Ball::update() {
    
    if(x - rad < 0) {
        x = rad;
        vx *= friction;
    } else if(x + r > ofGetWidth()) {
        x = ofGetWidth() - rad;
        vx *= friction;
    }
    
    
    if(y - rad < 0) {
        y = rad;
        vy *= friction;
    } else if(y + rad > ofGetHeight()) {
        y = ofGetHeight() - rad;
        vy *= friction;
    }
    vy += gravity;
    x += vx;
    y += vy;
    
}

void Ball::draw() {
    
    ofSetColor(r, g, b);
    ofCircle(x, y, rad);
}