//
//  rectangle.cpp
//  Week2_Atan
//
//  Created by Annelie Koller on 9/27/14.
//
//

#include "rectangle.h"



//------------------------------------------------------------------
rectangle::rectangle(int itemNumber){ // the slot of each object
    
    // whatever is staying the same (relative to itself)
    
    catchUpSpeed = (itemNumber+1)*0.03f;
    
    red = itemNumber*30;
    green = itemNumber*itemNumber;
    blue = abs(255-itemNumber*20);
    
    //    cout << red << " " << green << " " << blue << endl;
    
    pos.set(0,0);
    prevPos.set(0,0);
    
}


//------------------------------------------------------------------
void rectangle::draw() {
    
    sinOfTime = sin( ofGetElapsedTimef() * 3 );
    sinOfTimeMapped = ofMap( sinOfTime, -1, 1, 5, 50);
    
    //    cout << sinOfTimeMapped << endl;
    
    
	ofFill();
    
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    
    ofPushMatrix();
    
    ofTranslate(pos.x-15, pos.y-15); // what's the third value?
    ofRotate(angle * RAD_TO_DEG/2);
    
    ofCircle(50, 50, 10);
    ofSetColor(red,green,blue);
    
    ofRect(0, 0, 20, sinOfTimeMapped); // anchor point at the center of the rect + draw
    
    ofCircle(-50, -50, 10);
    
    ofPopMatrix();
    
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
    
    pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y;
    
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    
    angle = atan2(dy, dx);
    
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    
}