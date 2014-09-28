//
//  spiral.cpp
//  Wk_2_Ex2_Spirals_COS_SIN
//
//  Created by Annelie Koller on 9/26/14.
//
//

#include "ofSpiral.h"


ofSpiral::ofSpiral(){
    
    
}


void ofSpiral::setup(){
    
    a = 0;
    b = 0;
    
    pos = ofPoint(ofGetWidth()/2, ofGetHeight()/2);
    
    //Screen center
    
    colorStep = 0;

    
}

    void ofSpiral::update(){

    
}

void ofSpiral::draw(){
    
    
    //Change a
    
    a += b * DEG_TO_RAD;
    
    //a holds values in radians, b holds values in degrees,
    //so when changing a we multiply b to DEG_TO_RAD constant  //Change b
    
    b = b + 0.05;  //Shift pos in direction defined by angle a
    
    lastPos = pos;    //Store last pos value
    
    ofPoint d = ofPoint( cos( a ), sin( a ) );
    
    float len = 5;
    
    pos += d * len;
    
    //Change color each 100 steps
    
    if ( colorStep % 100 == 0 ) {
        //Generate random color
        color = ofColor(ofRandom( 0, 255 ),
                        ofRandom( 0, 255 ),
                        ofRandom( 0, 255 ) );
    }
    
    colorStep++;
    
    //Draw line segment
    
    ofSetColor( color );
    
    ofLine(lastPos, pos);
    
    
}