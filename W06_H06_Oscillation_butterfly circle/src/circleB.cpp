//
//  circle.cpp
//  Week2_exercise_pendulum
//
//  Created by Annelie Koller on 10/8/14.
//
//

#include "circleB.h"
#include "testApp.h"

circleB::circleB(float _CentreX, float _CentreY){
    
    CentreX = _CentreX;
    CentreY = _CentreY;
  
    
    //noiseSeed(int(ofRandom(1000)));
    angnoise = ofRandom(10);
    lastX = 9999;
    strokeCol = ofRandom(1) + 0.5;
    r = ofRandom(0,255);
    g = ofRandom(0,255);
    b = ofRandom(0,255);
    angle = 0;
}

void circleB::update() {
    
    float radnoise;
    if (angle > PI) {
        radnoise = (angle+1)/2*PI * strokeCol;
    } else {
        radnoise = ((2*PI-angle)+1)/2*PI * strokeCol;
    }
    radius = (ofNoise(radnoise) * (ofGetWidth()/4));
    
    angle += (ofNoise(radnoise) * 1.5);
    if (angle > 2*PI) {
        angle -= 2*PI;
        strokeCol++;
        ofClearAlpha();
    } else if (angle < 0) {
        angle += 2*PI;
        strokeCol++;
        ofClearAlpha();
    }
    

    float wid = (ofNoise(radnoise) * 150) - 75;
    float rad = angle + PI/2;
    float x1 = CentreX + (radius * cos(rad));
    float y1 = CentreY + (radius * sin(rad));
    
    float outerRadius = radius + wid/2;
    float outerX = CentreX + (outerRadius * cos(rad));
    float outerY = CentreY + (outerRadius * sin(rad));
    
}

void circleB::draw() {
    
    if (strokeCol > 10) {
        //init(CentreX, CentreY);
        if (ofRandom(2) > 1) {
            b += 40;
            if (b > 250) { b = 0; }
        } else {
            g += 40;
            if (g > 250) { g = 0; }
        }
    }
    
    if (lastX < 9999) {
        ofSetLineWidth(0.7);
        ofColor(strokeCol * 40, g, b, 250);
        ofLine(x1, y1, lastX, lastY);
        ofSetLineWidth(0.5);
        ofColor(strokeCol * 40, g, b, 150);
        ofLine(CentreX, CentreY, outerX, outerY);
    }
    
    lastX = x1;
    lastY = y1;
    lastOuterX = outerX;
    lastOuterY = outerY;
}
    


