#include "testApp.h"
#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //vagRounded.loadFont("vag.ttf", 32);
    
    ofBackground(0,0,0);
	ofSetVerticalSync(true); //slows down animation
    
    mySqr.posa.x = 10;
	mySqr.posa.y = 500;
	mySqr.posb.x = 1014;
	mySqr.posb.y = 500;
    
    mySqr.radiusa = 30;
	mySqr.radiusb = 200;
    
	mySqr.interpolateByPct(0);	// start at 0 pct
	pct = 0;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    // to see pct in the console
//	printf("%f \n", pct);
//    
//	pct += 0.035f;							// increase by a certain amount
//	if (pct > 1) {
//		pct = 0;							// just between 0 and 1 (0% and 100%)
    
    
//	}
    
    pct = (float) mouseY / (float) ofGetHeight();
    
	mySqr.interpolateByPct(pct);		// go between pta and ptb

}

//--------------------------------------------------------------
void testApp::draw(){
    
    mySqr.draw();
    
    ofSetColor(255,122,220);
    ofDrawBitmapString("mouse height controls interpolation (pct = " + ofToString(pct) + ")", 20, 20);
    
    //vagRounded.drawString(eventString, 98,198);
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
    
//    int ti = ofGetElapsedTimeMillis();
//    ofstream myfile;
//    myfile.open ("test.txt");
//    myfile << ti; //writes to txt time user pressed - i.e response time
//    myfile.close();
//    sprintf(eventString,"%i",ti, 20, 20, 320);

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
