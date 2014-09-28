//
//  rectangle.h
//  Week2_Atan
//
//  Created by Annelie Koller on 9/27/14.
//
//

#ifndef __Week2_Atan__rectangle__
#define __Week2_Atan__rectangle__

#include <iostream>
#include "ofMain.h"


class rectangle {
    
public:
	
    rectangle(int itemNumber);
    
    void	draw();
    void	xenoToPoint(float catchX, float catchY);
    void    update();
	
    ofPoint		pos;
    ofPoint     prevPos;
    
    float		catchUpSpeed;
    float       angle;
	
    int         red;
    int         green;
    int         blue;
    
    // sin
    float sinOfTime;
    float sinOfTimeMapped;
    
	
};

#endif /* defined(__Week2_Atan__rectangle__) */
