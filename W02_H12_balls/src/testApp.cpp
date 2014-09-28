#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0,0,0);
    ofSetFrameRate(60);
    ofEnableSmoothing();
    ofNoFill();
    ofSetLineWidth(5);
    
    nBalls = 10;
    
    myBall = new Ball*[nBalls];
    
    for(int i = 0; i<nBalls; i++) {
        float x = ofRandom(0, ofGetWidth());;
        float y = ofRandom(0, ofGetHeight() * 0.35);;
        int rad = ofRandom(10, 50);
        int id = i;
        
        myBall[i] = new Ball(x, y, rad);
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i = 0; i<nBalls; i++) {
        myBall[i]->update();
        
    }
}



//--------------------------------------------------------------
void testApp::draw(){
    
    for(int i = 0; i<nBalls; i++) {
        myBall[i]->draw();
    }

}

//--------------------------------------------------------------


