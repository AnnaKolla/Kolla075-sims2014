#pragma once

#include "ofMain.h"
#include "spring.h"
#include "particle.h"
//#include "ball.h"

#define numXeno 11

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
    
    //bool    bDragging;
    
    //vector<Spring>      springList;
    //vector<SpringJoint> jointList;
    
    //ball myBall[numXeno];
    
    vector <particle *> particles;
    vector <spring > springs;
    
    void makeSpring(particle * a, particle * b);
    
    float radius;
};
