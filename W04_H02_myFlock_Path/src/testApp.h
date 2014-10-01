#pragma once

#include "ofMain.h"
#include "Particle.h"
#include "path.h"

class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    
    ofPoint dest1, dest2;
    Particle car1, car2;
    path path1;
    path path2;
};