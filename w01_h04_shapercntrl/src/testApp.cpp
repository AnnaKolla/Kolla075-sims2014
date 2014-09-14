#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);

	
	ofBackground(30,30,30);
    
    // set the "a" and "b" positions of the rectangle...
    
    for (int i = 0; i < 10; i++){
	
	myArect[i].posa.x = 0;
	myArect[i].posa.y = 10 + i*20;
	myArect[i].posb.x = 400;
	myArect[i].posb.y = 10 + i*10;
    myArect[i].shaper = 0.4 + 0.1 * i;  //why the plus?
    
	myArect[i].interpolateByPct(0);	// start at 0 pct
    }
	pct = 0;
    
 

}

//--------------------------------------------------------------
void testApp::update(){
    
    pct += 0.003f;							// increase by a certain amount
	if (pct > 1) pct = 0;					// just between 0 and 1 (0% and 100%)
    
    for (int i = 0; i < 10; i++){
	myArect[i].interpolateByPct(pct);		// go between pta and ptb
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    for (int i = 0; i < 255; i++){
        
        ofSetColor(pct*1000,i*pct,i);
        

        
    }
    
    for (int i = 0; i < 10; i++){
    
      
        
        float sizex = 10+(i*5);
        float sizey = 10+(i*5);
        myArect[i].draw(sizex,sizey);
        
    
        
        
    }
    
    for (int i = 0; i < 255; i++){
        
        ofSetColor(255,0,0);
        
      
   
    }
    
    
    

//        for (int i = 0; i < 10; i++){
//             ofSetColor(255,255,255);
//            ofLine(0,i*20, ofGetWidth(), i*20);
    

//}
    
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
