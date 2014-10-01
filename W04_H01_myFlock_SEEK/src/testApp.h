#pragma once

#include "ofMain.h"
#include "Particle.h"

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
    

    
    // FOR RANDOM AND ARBITRARY POSITIONING AND COLOR
    void setRandomPos();
    //void setRandomColor();
    ofPoint randPos;
    void setRandomDest(ofPoint _dest);
    
    // POSITION VARIABLES
    unsigned int randX;
    unsigned int randY;
    
    
    // CREATE A VECTOR OF PARTICLE CARS
    vector <Particle> cars;
    
    // CREATE A VECTOR OF POINTS FOR THE DESTINATIONS
    vector <ofPoint> dest;
    
};
