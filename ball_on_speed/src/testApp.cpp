#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0,0,0);
	ofSetFrameRate(60);
	ofSetWindowTitle("sqr - class example_1");
	
	ofEnableSmoothing();
	ofNoFill();
}

//--------------------------------------------------------------
void testApp::update(){
    
    mySqr.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    
    mySqr.draw();
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
