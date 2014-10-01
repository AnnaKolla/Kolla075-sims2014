#include "testApp.h"



//--------------------------------------------------------------
void testApp::setup(){
    ofSeedRandom();
    
    
    dest1 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    dest2 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    
    car1.setInit( ofGetWindowSize() / 2, ofPoint(10, -5) );
    car2.setInit( ofGetWindowSize() / 2, ofPoint(10, 5) );
    
    car1.color = ofColor(0,255,0);
    car2.color = ofColor(0,0,255);
    
    path1.color = ofColor(0,0,0);
    path2.color = ofColor(50,50,255);
    
    //ofBackground(0);
    
    ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
    
    

    
    // apply steering force
    car1.seek( dest1 );
    car2.seek( dest2 );
    
    // apply repelling force
    float area = 200;
    if( car1.getPosition().distance( car2.getPosition() ) < area ){
        car1.color = ofColor(255,0,0);
        car2.color = ofColor(255,0,0);
        
        car1.addRepulsionForce( car2.getPosition(), area,  0.1 );
        car2.addRepulsionForce( car1.getPosition(), area, 0.1 );
    }else{
        car1.color = ofColor(0,255,0);
        car2.color = ofColor(0,0,255);
    }
    
    // update physics
    car1.update();
    car2.update();
    
    if( car1.getPosition().distance(dest1) < 5){
        dest1 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
    
    if( car2.getPosition().distance(dest2) < 5){
        dest2 = ofPoint( ofRandomWidth(), ofRandomHeight() );
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(255);
    
    ofSetColor( path1.color );
    path1.draw();
    
    ofSetColor( path2.color );
    path2.draw();
    
    ofSetColor( car1.color );
    ofCircle( dest1, 4 );
    car1.draw();
    
    ofSetColor( car2.color );
    ofCircle( dest2, 4 );
    car2.draw();
}

//--------------------------------------------------------------
