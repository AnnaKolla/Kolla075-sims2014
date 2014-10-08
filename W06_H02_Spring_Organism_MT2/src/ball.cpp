//
//  ball.cpp
//  Spring_Organism
//
//  Created by Annelie Koller on 10/7/14.
//
//

#include "ball.h"

#include "testApp.h"

ball::ball(float _x, float _y, int _radB)

{
    x = _x;
    y = _y;
    radB = _radB;
    maxv = 20; // max velocity
    vx = ofRandom(maxv * -1, maxv);
    vy = ofRandom(0, maxv);
    gravity = 0.03;
    friction = -0.8;
    
    r, g, b = ofRandom(0, 255); // ball border color
    catchUpSpeed = 0.03f;
    
    
}

void ball::update() {
    
    //    if(x - rad < 0) {
    //        x = rad;
    //        vx *= friction;
    //) {
    //        x = ofGetWidth() - rad;
    //        vx *= friction;
    //    }
    //
    
//    if(pos - radB < 0) {
//        y = radB;
//        vy *= friction;
//    } else if(y + radB > ofGetHeight()) {
//        y = ofGetHeight() - radB;
//        vy *= friction;
//    }
    vy += gravity;
    x += vx;
    y += vy;
    
}

void ball::draw() {
    
    ofSetColor(r, g, b);
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofCircle(pos.x, pos.y, radB);
}

void ball::xenoToPoint(ofPoint catchB){
    
  
    
    pos = catchUpSpeed * catchB + (1-catchUpSpeed) * pos;
    //pos.y = catchUpSpeed * catch + (1-catchUpSpeed) * pos.y;
}


//------------------------------------------------------------------

