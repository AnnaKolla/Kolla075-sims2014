//
//  aRect.cpp
//  Xenos
//
//  Created by Annelie Koller on 9/22/14.
//
//

#include "aRect.h"

//------------------------------------------------------------------
aRect::aRect(){
    
	catchUpSpeed = 0.03f;
    
    
}

//------------------------------------------------------------------
void aRect::draw(int red, int yellow, int blue) {
    
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(red, yellow,  blue);
    ofCircle(pos.x, pos.y, xenoR);
}

//------------------------------------------------------------------
void aRect::xenoToPoint(float catchX, float catchY){
    
    
    
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
}


//------------------------------------------------------------------



