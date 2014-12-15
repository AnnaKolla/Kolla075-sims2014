#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
   void keyPressed(int key);
    
    ofEasyCam       cam;
    
    ofTexture       heightMap;
    ofShader        normalShader;
    ofFbo           normalFbo;
    
    ofVboMesh       mesh;
    ofShader        terrainShader;
    
    bool            bWireframe;

     ofPolyline cur;

//    
       ofLight light;

//    ofTexture text;
//    
//    GLUquadricObj *quadric;
//    
//    void drawWithMesh();
    
};

//void setNormals( ofMesh &mesh );