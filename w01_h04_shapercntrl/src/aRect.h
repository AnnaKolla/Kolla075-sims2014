//
//  aRect.h
//  Square_interpolate_3
//
//  Created by Annelie Koller on 9/14/14.
//
//

#ifndef __Square_interpolate_3__aRect__
#define __Square_interpolate_3__aRect__

#include <iostream>

#include "ofMain.h"

class aRect {
    
public:
	
    aRect();
	
    void draw (float sizex , float sizey); //why there and not below?
    void interpolateByPct(float myPct);
   
    
    ofPoint		pos;
    ofPoint		posa;
    ofPoint		posb;
    float		pct;	// what pct are we between "a" and "b"
    float		shaper;
    //float       size;

    float r;
    float g;
    float b;
    
   
	
};

#endif /* defined(__Square_interpolate_3__aRect__) */
