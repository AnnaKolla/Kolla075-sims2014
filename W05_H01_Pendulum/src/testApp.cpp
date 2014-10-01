#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    
    
    ofSetVerticalSync(true);
    ofBackground(0);
    ofSetCircleResolution(100);
    ofSetFrameRate(60);
    
    origin = ofPoint( 512, 300 );
	pos = ofPoint( 600, 200 );
	velocity = ofPoint( 100, 0 );
   

}

//--------------------------------------------------------------
void testApp::update(){
    
    //Constants
	float dt = 1.0 / 60.0;         //Time step for euler's method
	float mass = 0.1;              //Mass of a ball
	float rubberLen = 200.0;       //Segment's length
	float k = 0.5;                 //Segment's stiffness (constant)
	ofPoint g( 0.0, 9.8 );         //Gravity force
    
    
    //Compute Hooke's force
	ofPoint angle = pos - origin;
	float len = angle.length();   //Vector's length
	float hookeValue = k * (len - rubberLen);
	angle.normalize();            //Normalize vector's length
	ofPoint hookeForce = angle * (-hookeValue);   //F = x * -1  => hookes = displacement * -constant(normalised vector)
    
    //Update velocity and pos
	ofPoint force = hookeForce + g;  //Resulted force
	ofPoint acel = force / mass;        //Second Newton's law F=M*A
	velocity += acel * dt;              //Euler method
	pos += velocity * dt;            //Euler method

}

//--------------------------------------------------------------
void testApp::draw(){
 
    
	//Set white background
	ofBackground( 255, 255, 255 );
    
	//Draw rubber as a blue line
	ofSetColor( 0, 0, 255 );                //Set blue color
	ofLine( origin.x, origin.y, pos.x, pos.y ); //Draw line
    
	//Draw ball as a red circle
	ofSetColor( 255, 0, 0 );                //Set red color
	ofFill();                               //Enable filling
	ofCircle( pos.x, pos.y, 20 );           //Draw circle


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


