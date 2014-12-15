#include "ofApp.h"

/* cylinder mesh example by kyle macdonald! Thank you!*/

void ofApp::setup() {
    
        ofSetVerticalSync(true);
        ofEnableDepthTest();
    
        mesh.setMode(OF_PRIMITIVE_TRIANGLES);

        width = 600;
        height = 600;
    
        // Initial Allocation
        //
        fluid.allocate(maxRadius, length, 0.5);
    
        // Seting the gravity set up & injecting the background image
        //
        fluid.dissipation = 0.99;
        fluid.velocityDissipation = 0.99;
    
        fluid.setGravity(ofVec2f(0.0,0.0));
        //    fluid.setGravity(ofVec2f(0.0,0.0098));
    
        //  Set obstacle
        //
        fluid.begin();
        ofSetColor(0,0);
        ofSetColor(255);
        ofCircle(width*0.5, height*0.35, 40);
    
    int rings = 32, resolution = 32;
    
    float length = 512, maxRadius = 256;
    
    for(int i = 0; i < rings; i++) {
        
        float radius = ofNoise(i / 4.) * maxRadius;
        
        ofVec3f offset(0, 0, ofMap(i, 0, rings, -length, length) / 2);
        
        
        for(int j = 0; j < resolution; j++) {
            
            float theta = ofMap(j, 0, resolution, 0, 360); //j/PI * 32;
            
            ofVec2f cur(radius, 0);
            
            cur.rotate(theta);
            
            mesh.addVertex(offset+cur);
            
            mesh.addColor(ofFloatColor((i * j) % 2 == 0 ? 255 : 0));
            
            mesh.addVertex(offset);
            
            
            mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
            
            
        }
    }
    
    for(int i = 0; i < rings - 1; i++) {
        for(int j = 0; j < resolution; j++) {
            int sw = i * resolution + j, se = sw + 1;
            if(j + 1 == resolution) {
                se -= resolution;
            }
            
            int nw = sw + resolution, ne = se + resolution;
            mesh.addTriangle(sw, se, nw);
            mesh.addTriangle(nw, se, ne);
            mesh.addTriangle(nw, sw, se);
        }
    }

    
    
    fluid.end();
    fluid.setUseObstacles(false);
    
    // Adding constant forces
    //
    fluid.addConstantForce(ofPoint(width*0.5,height*0.85), ofPoint(0,-2), ofFloatColor(0.5,0.1,0.0), 10.f);
    
   ofSetWindowShape(width, height);
    
}

//--------------------------------------------------------
void ofApp::update() {
    
    
        // Adding temporal Force
        //
        ofPoint m = ofPoint(mouseX,mouseY);
        ofPoint d = (m - oldM)*10.0;
        oldM = m;
        ofPoint c = ofPoint(width*0.5, height*0.5) - m;
        c.normalize();
        fluid.addTemporalForce(m, d, ofFloatColor(c.x,c.y,0.5)*sin(ofGetElapsedTimef()),3.0f);
    
        //  Update
        //
        fluid.update();
    
        ofSetWindowTitle(ofToString(ofGetFrameRate()));
    
    
}

//--------------------------------------------------------
void ofApp::draw() {
    
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
    
    fluid.draw();
    
    //ofBackground(0);
    cam.begin();
    glEnable(GL_DEPTH_TEST);
    //ofSetColor(255);
    ofRotateY(90);
    mesh.draw();
    cam.end();
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//    
//        if( key == 'p')
//            bPaint = !bPaint;
//        if( key == 'o')
//            bObstacle = !bObstacle;
//        if( key == 'b')
//            bBounding = !bBounding;
//        if( key == 'c')
//            bClear = !bClear;
//    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
