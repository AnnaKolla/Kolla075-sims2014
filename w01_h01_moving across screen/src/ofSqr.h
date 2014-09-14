//
//  ofSqr.h
//  ball_on_speed
//
//  Created by Annelie Koller on 9/10/14.
//
//

#ifndef _OF_SQR
#define _OF_SQR

#include "ofMain.h"


class ofSqr{
    
public:
	
    ofSqr();
	
    void draw();
    void interpolateByPct(float myPct);
    
    ofPoint		pos;
    
    ofPoint		posa;
    ofPoint		posb;
    
    float		pct;	// what pct are we between "a" and "b"

};


#endif
