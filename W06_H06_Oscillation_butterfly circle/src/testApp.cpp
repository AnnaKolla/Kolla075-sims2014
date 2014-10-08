#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
	
	ofBackground(0,0,0);
	
	ofSetCircleResolution(100);
    
   ofSetFrameRate(60);
    
 
    
    nCircle = 100;

   myCircle = new circleB*[nCircle];

    for(int i = 0; i<nCircle; i++) {
//    
//    
//    //float CentreX = xpos;
//    //float CentreY= ypos;
//    //int rad = ofRandom(10, 50);
//    int id = i;
//    
//    
    myCircle[i] = new circleB(CentreX, CentreY);
}


}

//--------------------------------------------------------------
void testApp::update(){
    
    for(int i = 0; i<nCircle; i++) {
        myCircle[i]->update(CentreX, CentreY));
        
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    float xOrig = ofGetWidth()/2;
    float yOrig = ofGetHeight()/2;
    
    float xpos	= xOrig + radius * cos(angle);
    
    float ypos = yOrig + radius * sin(angle);
    
    
//

	for ( int i=0; i < 30; i++ ){
        
        float angle = ofGetElapsedTimef()*(i*0.2);
        
        float radius = 20*i;
        
        ofColor color = ofColor::fromHsb(0,255,255);
        color.setHue(10*i);
        ofSetColor( color);

    
    ofSetLineWidth(1);
    
    ofLine(xOrig, yOrig, xpos, ypos);
    
    }
    
    
    for(int i = 0; i<nCircle; i++) {
        CentreX = xpos;
        CentreY = ypos;
        myCircle[i]->draw(CentreX, CentreY));
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


