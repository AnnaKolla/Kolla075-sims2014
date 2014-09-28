#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    ofSetFrameRate(60);
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    
   	
	float xorig = ofGetWidth()/2 ;
	float yorig = ofGetHeight()/2;
    float circR = 5;
   
    
	for (int i = 0; i < 200; i++){
        
		float radius = 30 + i * 20;
        
		float angle = ofGetElapsedTimef() * (1 + i/10.0);
        
		float x = xorig + radius * cos(angle);
		float y = yorig + radius * -sin(angle);
        
        float r = 100;
        float g = 10;
        float b = 5;
		
		ofSetRectMode(OF_RECTMODE_CENTER);
        
		ofSetColor(r*i,(g*i/2),b);
        
        ofCircle(x, y, circR * i);
        
	}	

    
	for (int i = 0; i < 200; i++){
        
		float radius = 20 + i * 10;
        
		float angle = ofGetElapsedTimef() * (1 + i / 10.0);
        
		float x_a = xorig + radius * cos(angle);
		float y_a = yorig + radius * -sin(angle);
        
        float r = 5;
        float g = 10;
        float b = 100;
		
		ofSetRectMode(OF_RECTMODE_CENTER);
        
		ofSetColor(r,(g*i/2),b *i);
        
        ofCircle(x_a,y_a,(circR + i));
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
