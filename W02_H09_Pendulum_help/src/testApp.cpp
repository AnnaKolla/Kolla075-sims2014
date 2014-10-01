#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetCircleResolution(100);
    
    angleAdd = 0.01;
    angleChange = 0.01;
    
    float length = 150; //radius
 
   float angle = 0;

   

}

//--------------------------------------------------------------
void testApp::update(){
    
    angle = angle + angleAdd;
   
    
    if (angle >= angleStop) {
        
        angleStop = PI;

        angle = angle - angleChange;

     
    }
    

}

//--------------------------------------------------------------
void testApp::draw(){
 
    float xorig = ofGetWidth()/2;
    float yorig = ofGetHeight()/2;
    float length = 150; //radius
    
    
    
    ofPoint temp;
    
    float x = xorig + length * cos(angle);
	float y = yorig + length * -sin(angle);
	

    temp.x = x;
    temp.y = y;
    
    points.push_back(temp);
	if (points.size() > 30){
		points.erase(points.begin());
	}
    
    ofSetRectMode(OF_RECTMODE_CENTER);
	ofSetColor(255,0,0);
    ofCircle(x, y, 30);
    ofLine(xorig, yorig, x, y);


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


