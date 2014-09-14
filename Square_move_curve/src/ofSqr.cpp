//
//  ofSqr.cpp
//  ball_on_speed
//
//  Created by Annelie Koller on 9/10/14.
//
//

#include "ofSqr.h"

ofSqr::ofSqr(){
    
 
}


void ofSqr::draw(){
    
    ofSetColor(255,0,0);
    ofFill();
    ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofCircle(pos.x, pos.y, radius);
}

void ofSqr::interpolateByPct(float myPct){
	
    pct = myPct;
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
	
    radius = (1-pct) * radiusa + (pct) * radiusb;
	
}