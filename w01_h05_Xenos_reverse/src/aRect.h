//
//  aRect.h
//  Xenos
//
//  Created by Annelie Koller on 9/22/14.
//
//

#ifndef __Xenos__aRect__
#define __Xenos__aRect__

#include <iostream>

#include "ofMain.h"

class aRect {
    
public:
	
    aRect();
    
	void	xenoToPoint(float catchX, float catchY);
    void    draw (int red, int yellow, int blue);
    void    interpolateByPct(float myPct);
	
    ofPoint		pos;

    
    float		catchUpSpeed;		// take this pct of where I want to be, and 1-catchUpSpeed of my pos
   
    float		xenoR;

    
    
  
   
	
    
};

#endif /* defined(__Xenos__aRect__) */
