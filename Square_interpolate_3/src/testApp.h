#pragma once
#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "aRect.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
    
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
    
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    aRect myArect[10];
    float pct;
    float sizex;
    float sizey;
    
   // Tweenzor::add ( &lerpAmount , lerpAmount, 1.0f , 0.0f , 1.0f , EASE_OUT_QUAD);
    
    
};

#endif