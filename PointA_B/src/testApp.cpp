#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
	ofSetVerticalSync(true);
	
	
	ofBackground(0, 0, 0);
	
	
	myRect.posa.x = 0;
	myRect.posa.y = 400;
	myRect.posb.x = ofGetWidth();
	myRect.posb.y = 400;
	

    
    
    inc = 0.01;
    button = true;

}

//--------------------------------------------------------------
void testApp::update(){
    
    pct += inc;
    pct = fmod(pct, 1);
	
	myRect.interpolateByPct(pct);

}

//--------------------------------------------------------------
void testApp::draw(){
    
    myRect.draw();
    
    ofDrawBitmapString("pt a: " + ofToString(myRect.posa.x) + ", " + ofToString(myRect.posa.y), 20, 20);
    ofDrawBitmapString("pt b: " + ofToString(myRect.posb.x) + ", " + ofToString(myRect.posb.y), 20, 35);

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
    
    if (button) {
        myRect.posa.x = x;
        myRect.posa.y = y;
    } else {
        myRect.posb.x = x;
        myRect.posb.y = y;
    }
    
    button = !button;
    pct = 0;

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
