#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofEnableSmoothing();
    ofSetCircleResolution(60);
    //ofBackground(204, 204, 204);
    ofSetFullscreen(true);
    
    ofSetFrameRate(30);
    radius = 10;
    centX = 50;
    centY = 50;
    
    startNoise = ofRandom(0,10);
    noiseStep = 0.1;
    
   ofCircle(centX, centY, radius);
}


//--------------------------------------------------------------
void testApp::update(){
    
    float stepStep = 0.01;
    
    startNoise += 0.01;
    noiseStep += stepStep;
    if (noiseStep > 5) {
        stepStep *= -1;
    } else if (noiseStep < -5) {
        stepStep *= -1;
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    float x, y;
    float noiseval = startNoise;
    
   ofSetColor(255,20,150);
    ofFill();
    
    ofPushMatrix();{
    
       ofBeginShape();
    
  
    
    for (float ang = 90; ang < 400; ang += 10) {
        
        noiseval += noiseStep;
        
        radVariance = 20 * noiseval;
        
        thisRadius = radius + radVariance;
        rad = ofNoise(ang/45, ofGetElapsedTimef()*0.15);
        
        x = centX + (thisRadius * cos(rad)*PI);
        y = centY + (thisRadius * sin(rad)*PI);
        
        ofCurveVertex(x,y);

    
    ofCurveVertex((ofGetWidth()/2)+20, ofGetHeight()/2);
    ofCurveVertex((ofGetWidth()/2)+20, ofGetHeight()/2);
    ofCurveVertex(x+20, y+2);
        
          }
    
    ofEndShape();
        
        ofPopMatrix();
    }
    
    float retValue = sin(value);
    float count = float((value / 10));
    for (int i = 0; i < count; i++) {
        retValue *= sin(value);
    }
    return retValue;
}




//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
