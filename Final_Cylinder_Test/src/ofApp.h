#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
  
    
    ofMesh mesh;
    ofEasyCam cam;
    ofPolyline cur;
    
    ofPolyline polyline;
    
    float time0;
    float phase;
    float distortAmount;
    
    ofLight light;
    
   
    ofShader shader;
    ofImage image;
    ofTexture text;
    
    GLUquadricObj *quadric;
    
    void drawWithMesh();
    
};

//void setNormals( ofMesh &mesh );