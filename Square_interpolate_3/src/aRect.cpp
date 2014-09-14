//
//  aRect.cpp
//  Square_interpolate_3
//
//  Created by Annelie Koller on 9/14/14.
//
//

#include "aRect.h"

aRect::aRect(){
	shaper = 0.5;
    
}

//------------------------------------------------------------------
void aRect::draw(float sizex, float sizey) {
    
	ofFill();
    
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    //ofSetColor(255,0,135);
    ofRect(pos.x, pos.y, sizex, sizey);
}


//------------------------------------------------------------------
void aRect::interpolateByPct(float myPct){
	
	
	// powf (2, 3) = 8
	
	pct = powf(myPct, shaper);
	pos.x = (1-pct) * posa.x + (pct) * posb.x;
	pos.y = (1-pct) * posa.y + (pct*2) * posb.y;
    
    
}