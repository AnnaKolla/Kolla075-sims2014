#pragma once

#include "ofMain.h"
#include "ofxFluid.h"

class ofApp : public ofBaseApp{

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
    
        ofMesh mesh;
        ofEasyCam cam;
        ofPolyline cur;
    
        ofxFluid fluid;
    
        ofVec2f oldM;
        ofVec3f offset;
        int     width,height ;
        float  rings, resolution, length, maxRadius;
        bool    bPaint, bObstacle, bBounding, bClear;
		
};
