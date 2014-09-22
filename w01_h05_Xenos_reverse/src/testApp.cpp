#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    // macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that:
	
	ofSetVerticalSync(true);
	
	// set background:
	
	ofEnableAlphaBlending();
	ofBackground(0,0,0);
	
	
	// set the position of the rectangle:
    
    for (int i = 0; i < numXeno; i++){
        
    myArect[i].catchUpSpeed = (1+i)*0.03f;
	
	myArect[i].pos.x = 100 * i; //??
	myArect[i].pos.y = 100 * i; //??
    myArect[i].xenoR = 5 + i;
        
        
        
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    for (int i =0; i < numXeno; i++){
   
        
        myArect[i].xenoToPoint(mouseX,mouseY);
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
     for (int i = 0; i < numXeno; i++){

         
         
         
         int red = i*30;
         int yellow = i*i;
         int blue = abs (255 - i*10);
         myArect[i].draw(red, yellow, blue);
      
         
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
