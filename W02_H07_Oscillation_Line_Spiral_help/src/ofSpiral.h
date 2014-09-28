//
//  spiral.h
//  Wk_2_Ex2_Spirals_COS_SIN
//
//  Created by Annelie Koller on 9/26/14.
//
//

#ifndef __Wk_2_Ex2_Spirals_COS_SIN__spiral__
#define __Wk_2_Ex2_Spirals_COS_SIN__spiral__

#include <iostream>
#include "ofMain.h"


class ofSpiral{
    
    
    
public:
    
	void setup();
	void update();
	void draw();

    
    double      a, b;
    ofPoint     pos, lastPos;
    ofColor     color;
    int         colorStep;

    ofSpiral();

    
};

#endif /* defined(__Wk_2_Ex2_Spirals_COS_SIN__spiral__) */
