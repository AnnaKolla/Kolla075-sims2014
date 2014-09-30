#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    ofSetVerticalSync(true);
	ofSetFrameRate(60);
    
    ofSetCircleResolution(100);
    ofBackground(100,100,100);
    
    
    for (int i = 0; i < 1000; i++){
        
        Particle myParticle;
		
		myFireworks.push_back(myParticle);
	}
}

//--------------------------------------------------------------
void testApp::update(){
    
    for (int i = 0; i < myFireworks.size(); i++){
        
		myFireworks[i].resetForce();
		//myFireworks[i].addForce(0,0.1);
		myFireworks[i].addDampingForce();
		myFireworks[i].update();
	}
    

    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    
    for(int i = 0; i < myFireworks.size(); i++){
        //ofVertex(myFireworks[i].pos.x, myFireworks[i].pos.x);
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
    
    float xorig = 0;
	float yorig = 0;
	
	for (int i = 0; i < myFireworks.size(); i++){
        
		float angle = ofGetElapsedTimef() * (1 + i/100.0);
        
		float radius = 0.4;
        
        
        float xpos = xorig + radius / tan(angle);
		float ypos = yorig + radius * -sin(angle) * 5;
		
		float vx = xpos * 2.5;
		float vy = ypos * 1.5;
		
		
		myFireworks[i].setInitialCondition(mouseX,mouseY, vx, vy);
		
	}

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}


