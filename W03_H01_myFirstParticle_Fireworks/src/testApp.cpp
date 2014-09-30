#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofSetCircleResolution(100);
    ofBackground(100,100,100);
    
   
    
    
    counter=0;
    
    for (int i = 0; i < 800; i++){
        
        Particle myParticle;
		
		float vx = ofRandom(-4,4);
		float vy = ofRandom(-4,4);
        
		myParticle.setInitialCondition(300,300,vx, vy);
		
		myParticle.damping = ofRandom(0.001, 0.09);
		
		myFireworks.push_back(myParticle);
	}
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < myFireworks.size(); i++){
        
		myFireworks[i].resetForce();
		myFireworks[i].addForce(0,0.1);
		myFireworks[i].addDampingForce();
		myFireworks[i].update();
	}
    
    counter++;
    
    if (counter == 100){
		myParticle();
		counter = 0;
	}

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    for(int i = 0; i < myFireworks.size(); i++){
        ofVertex(myFireworks[i].pos.x, myFireworks[i].pos.x);
        myFireworks[i].draw();
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
void testApp::myParticle(){
	
	int posx = ofRandom(ofGetWidth()/2 - 25, ofGetWidth()/2 + 25);
	int posy= ofRandom(ofGetHeight()/2 - 25, ofGetHeight()/2 +25);
	
	for (int i = 0; i < myFireworks.size(); i++){
		float angle = ofRandom(0,4 * PI);
		float radius = ofRandom(0, 8);
		float vx =  radius * cos(angle);
		float vy =  radius * -sin(angle);
		
		
		myFireworks[i].setInitialCondition(posx,posy, vx, vy);
		
	}
}
