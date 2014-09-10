//
//  ofSqr.cpp
//  ball_on_speed
//
//  Created by Annelie Koller on 9/10/14.
//
//

#include "ofSqr.h"

ofSqr::ofSqr(){
    
    x = 0;      // give some random positioning
    y = ofGetHeight()/2;
    
    speedX = 1;
    //speedY = 1;
    
    w = 100;
    h = 100;

}


void ofSqr::update(){
    
    if(x < 0 ){
        x = 0;
        speedX *= -1;
    } else if(x > ofGetWidth()){
        x = ofGetWidth();
        speedX *= -1;
    }
    
    if(y < 0 ){
        y = 0;
        speedY *= -1;
    } else if(y > ofGetHeight()){
        y = ofGetHeight();
        speedY *= -1;
    }
    
    x+=speedX;
    y+=speedY;
}

void ofSqr::draw(){
    
    ofSetColor(150);
    ofFill();
    ofRect(x, y, w, h);
}
