#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
     //ofSetBackgroundAuto(false);
    
	ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
    
    ofEnableAlphaBlending();
	
	ofSetCircleResolution(100);
    ofSetFrameRate(150);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255,0,0);
    
    float xPos = ofMap(sin(ofGetElapsedTimef()), -1, 1, 0, ofGetWidth());
    float yPos = ofGetHeight()/2;
    
    
    for (int i = 0; i < 20; i++){
    
    ofRect((xPos * i), yPos, 50, 50);
        
        
    }
   

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


