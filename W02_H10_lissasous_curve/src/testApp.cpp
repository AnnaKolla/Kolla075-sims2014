#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    
	//ofEnableAlphaBlending();
    //ofSetFrameRate(60);
	ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    
   

}

//--------------------------------------------------------------
void testApp::draw(){
    
     ofTranslate(ofGetWidth()/2, ofGetHeight()/2);

    ofSetColor(255,0,0);
    
    for (int i = 0; i < 1200; i++){
    
        float xPct = (i * mouseX) * 0.0001;
        float yPct = (i * mouseY) * 0.0001;
        
        float x = 400 * sin(xPct);
        float y = 200 * cos(yPct);
        
        ofRect (x,y, 2,2);
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

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
