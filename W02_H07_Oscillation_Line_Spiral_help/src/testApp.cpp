#include "testApp.h"
#include "ofMain.h"



//--------------------------------------------------------------
void testApp::setup(){
    
   // ofSetFrameRate( 60 );  //Set screen frame rate
    
    ofSetBackgroundAuto(false);
  
    ofEnableAlphaBlending();
    ofSetFrameRate(60);
    
 
    fbo.allocate( ofGetWidth(), ofGetHeight() );
    
    
    
    
    fbo.begin();
    
     ofBackground(255,255,255);
  
    fbo.end();  //Initialize variables
    
  

}

//--------------------------------------------------------------
void testApp::update(){
    
    fbo.begin();     //Begin draw to buffer
    
    for ( int i=0; i<200; i++ ) {
        mySpiral.update();
        mySpiral.draw();
    }
    
    fbo.end();       //End draw to buffer

}

//--------------------------------------------------------------
void testApp::draw(){
    
    //ofBackground( 255, 255, 255 );  //Set white background
    
    //Draw buffer
    ofSetColor( 255, 255, 255 );
    fbo.draw( 0, 0 );
    mySpiral.draw();
   
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
