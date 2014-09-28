#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    ofSetVerticalSync(true);
    
	ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
    
	ofBackground(0);
    
    for (int i = 0; i < 10; i++) { // The only place where I should declare the size of the vector
        myRectangle.push_back(rectangle(i)); // i = itemNumber, where it's located in the array
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < myRectangle.size(); i++) {
        myRectangle[i].xenoToPoint(mouseX, mouseY);
        myRectangle[i].pos.x += ofRandom(-2,2);
        myRectangle[i].pos.y += ofRandom(-2,2);
    }
    
    for (int i = 0; i < vector.size(); i++){
		vector[i].x += ofRandom(-1,1);
		vector[i].y += ofRandom(-1,1);
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    for (int i = 0; i < myRectangle.size(); i++) {
        myRectangle[i].draw();
    }
    
    ofSetColor(255, 85, 70);
    ofNoFill();
    
    ofBeginShape();
    
	for (int i = 0; i < vector.size(); i++){
		ofVertex(vector[i].x, vector[i].y);
    }
	ofEndShape();

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
