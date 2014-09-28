#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    
   //ofSetFrameRate(60);
    
   startAngle = 0;
   angleVel = 0.2;
  
    
}

//--------------------------------------------------------------
void testApp::update(){

    angle = startAngle + angleVel;

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
   for (int x = 0; x < ofGetWidth(); x + 24){
    
    //float x = ofMap(cos(angle), -1, 1, 0, ofGetWidth());
    
    float y = ofMap(sin(angle), -1, 1, 0, ofGetHeight());
        
        ofFill();
        
        ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
        
        ofSetColor(255,255,0);
        
        ofCircle(x,y,10);
        
       
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


