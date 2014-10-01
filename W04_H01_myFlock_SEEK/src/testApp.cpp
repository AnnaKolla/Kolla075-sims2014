#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    

  
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
    ofBackground(150, 150, 150);
    ofEnableAlphaBlending();
    
    
    for (int i = 0; i < 300; i++) {
        
        Particle myCar;
        
        ofSeedRandom();
        
        ofPoint destination;
        setRandomDest(destination);
        destination = ofPoint( ofRandomWidth(), ofRandomHeight());
        
        setRandomPos();
        myCar.setInit(randPos);
        
        //setRandomColor();
        //myCar.setColorCondition(randR, randG, randB);
        
        cars.push_back(myCar);
        dest.push_back(destination);
    }

}

//--------------------------------------------------------------
void testApp::update(){
    
    
    for (int i = 0; i < cars.size(); i++) {
        
        // APPLY A STEERING FORCE
        cars[i].seek(dest[i]);
        
        float area = 200;
        
        // REPULSION
        cars[i].addRepulsionForce(cars[i+1].pos, area, 0.1);
        
        // UPDATE PHYSICS
        cars[i].update();
        
        if (cars[i].pos.distance(dest[i]) < 5) {
            dest[i] = ofPoint(ofRandomWidth(), ofRandomHeight());
        }
    }
}



//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(0);
    
    for (int i = 0; i < cars.size(); i++) {
        
        ofCircle(dest[i], 4);
        cars[i].draw();
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

//--------------------------------------------------------------
void testApp::setRandomPos(){
    randPos.x = ofRandom(0, ofGetWidth());
    randPos.y = ofRandom(0, ofGetHeight());
    
}

//--------------------------------------------------------------
void testApp::setRandomDest(ofPoint _dest){
    _dest.x = ofRandom(0, ofGetWidth());
    _dest.y = ofRandom(0, ofGetHeight());
}
