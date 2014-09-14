//
//  aRect.h
//  PointA_B
//
//  Created by Annelie Koller on 9/14/14.
//
//

#ifndef __PointA_B__aRect__
#define __PointA_B__aRect__


#include "ofMain.h"

class aRect {
    
public:
	
    aRect();
	
    void draw();
    void interpolateByPct(float myPct);
    
    ofPoint		pos;
    ofPoint		posa;
    ofPoint		posb;
    
    float		pct;	// what pct are we between "a" and "b"
	
	
    float		radius;
	
    float		radiusa;
    float		radiusb;
    
    float       w;
    float       h;
    
};

#endif /* defined(__week1_point_changer__rectangle__) */


