#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    
    vector < ofPoint > points;
	
    float radius;
    float angle, xorig, yorig;
    float angleAdd;
    float angleStop;
    float x,y;
    
    float lenght;
    float angleChange;
    
    float aVelocity;     // Angle velocity
    float aAcceleration; // Angle acceleration
    float damping;
    
    
//    ofPoint origin;
//    ofPoint bob;
//    ofPoint velocity;
    
//    vector <ofPoint> origin;
//    vector <ofPoint> bob;
//    float x;
//    float y;
    //vector <ofPoint> len;
    
//    vector <ofPoint> pointSet;
//    
//    float radius, angle, xorig, yorig;
//    float radiusAdd;
//    float changeRadius, tanAngle;
//    float x, y;

};

#endif