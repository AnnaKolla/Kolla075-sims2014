//
//  aRect.cpp
//  PointA_B
//
//  Created by Annelie Koller on 9/14/14.
//
//

#include "aRect.h"


aRect::aRect(){
    w = 50;
    h = w;
}

//------------------------------------------------------------------
void aRect::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(255, 0, 0);
    ofRect(pos.x, pos.y, w, h);
}


//------------------------------------------------------------------
void aRect::interpolateByPct(float myPct){
    
	pct = myPct;
	
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct) * posb.y;
	
	radius = (1-pct) * radiusa + (pct) * radiusb;
	
}