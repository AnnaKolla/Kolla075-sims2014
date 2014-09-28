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
    
    
    float xOrig = ofGetWidth()/2;
    float yOrig = ofGetHeight()/2;
    

   
//    
//    float ang = ofGetElapsedTimef()* 0.5* TWO_PI; //angular velocity
//    
//    float drop =  amp * (cos(ang));
//	
    // x = amp * (sin(framecount/period * 2pi);

	for ( int i=0; i < 30; i++ ){
        
        float angle = ofGetElapsedTimef()*(i*0.2);
        
        
        float radius = 20*i;
        
        float xpos	= xOrig + radius * cos(angle);
        
        float ypos = yOrig + radius * sin(angle);
        
        
    
        
        ofColor color = ofColor::fromHsb(0,255,255);
        color.setHue(10*i);
        ofSetColor( color);
        
	
	ofCircle(xpos, ypos, 20);
    
    ofSetLineWidth(10);
    
    ofLine(xOrig, yOrig, xpos, ypos);
        
  
    
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


