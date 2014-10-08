#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0);
    
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    
    for( int i=0; i<11; i++ ){
        
        particle party;
        party.pos = ofPoint(ofGetWindowWidth()/2, 10 + i*195);
        particles.push_back( party );
    }
    
    
    spring s0, s1,s2,s3,s4, s5, s6;
    
    
    s0.set( &particles[0], &particles[1], 0.05, 200.0);
    s1.set( &particles[1], &particles[2], 0.05, 200.0 );
    s2.set( &particles[2], &particles[3], 0.05, 200.0 );
    s3.set( &particles[3], &particles[4], 0.05, 200.0);
    s4.set( &particles[4], &particles[5], 0.05, 200.0);
    s5.set( &particles[5], &particles[6], 0.05, 200.0);
    s6.set( &particles[5], &particles[4], 0.05, 200.0) ;

    
    //s0.setInitialCondition(400,400,0,0);
    springs.push_back(s0);
    
    
    ///s1.setInitialCondition(500,400,0,0);
    springs.push_back(s1);
    
   
    //s2.setInitialCondition(400,500,0,0);
    springs.push_back(s2);
    
    
    //s3.setInitialCondition(500,500,0,0);
    springs.push_back(s3);
    
    
    //s4.setInitialCondition(600,500,0,0);
    springs.push_back(s4);
    //
    //s5.setInitialCondition(600,500,0,0);
    springs.push_back(s5);
    
    //s6.setInitialCondition(600,500,0,0);
    springs.push_back(s6);
    
      bDragging = false;
    
    //spring mySpring;
    
    



}

//--------------------------------------------------------------
void testApp::update(){
    
    // on every frame
    // we reset the forces
    // add in any forces on the particle
    // perfom damping and
    // then update
    
    if( bDragging ){
        return;
    }
    
    
    springs[1].distance = 50+100 * sin(ofGetElapsedTimef());
    springs[2].distance = 50+100 * sin(ofGetElapsedTimef()+ PI);
    
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].resetForce();
    }
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].addForce(0,0.1f);
        particles[i].addRepulsionForce(mouseX, mouseY, 300, 0.7f);
        
        for(int j = 0; j<particles.size(); j++){
            particles[3].addAttractionForce(mouseX, mouseY, 800, 3);
            particles[0].addRepulsionForce(particles[0], 800, 2);
            //particles[1].addRepulsionForce(mouseX, ofGetHeight(), 800, 2);
            
        }
    }
    
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
    
    
    for (int i = 0; i < particles.size(); i++){
        particles[i].bounceOffWalls();
        particles[i].addDampingForce();
        particles[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    //    for(int i=0; i<particles.size(); i++){
    //        particles[i].draw();
    //    }
    
    //ofSetColor(255,173,0);
    
    ofSetColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    
    
    
    for( int i=0; i<particles.size(); i++ ){
        particles[i].draw();
    }
    
    for( int i=0; i< springs.size(); i++ ){
        springs[i].draw();
    }
    
    
    ofBeginShape();
    
    ofCurveVertex(particles[0].pos.x+10, particles[0].pos.y+10);
    ofVertex(particles[0].pos.x, particles[0].pos.y);
    ofCircle(particles[0].pos.x, particles[0].pos.y, 2);
    
   
    ofCurveVertex(particles[1].pos.x+10, particles[1].pos.y+10);
    ofVertex(particles[1].pos.x, particles[1].pos.y);
    ofCircle(particles[1].pos.x, particles[1].pos.y, 2);
    
    ofVertex(particles[2].pos.x, particles[2].pos.y);
     ofCurveVertex(particles[2].pos.x, particles[2].pos.y, particles[2].pos.z);
    ofCircle(particles[2].pos.x, particles[2].pos.y, 2);
    
    ofEndShape();
    
    ofBeginShape();
    ofVertex(particles[4].pos.x, particles[4].pos.y);
    ofCircle(particles[4].pos.x, particles[4].pos.y, 2);
    ofVertex(particles[3].pos.x, particles[3].pos.y);
    ofCircle(particles[3].pos.x, particles[3].pos.y, 2);
    ofVertex(particles[2].pos.x, particles[2].pos.y);
    ofCircle(particles[2].pos.x, particles[2].pos.y, 2);
    
    ofEndShape();
    
    ofBeginShape();
    
    ofVertex(particles[5].pos.x, particles[5].pos.y);
    ofCircle(particles[5].pos.x, particles[5].pos.y, 2);
    ofVertex(particles[4].pos.x, particles[4].pos.y);
    ofCircle(particles[4].pos.x, particles[4].pos.y, 2);
    ofVertex(particles[3].pos.x, particles[3].pos.y);
    ofCircle(particles[3].pos.x, particles[3].pos.y, 2);
    
    ofEndShape();
  
     for( int i=0; i<particles.size(); i++ ){
    
    ofCircle(particles[2].pos.x, particles[2].pos.y, 6);
     }
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
    
    switch (key){
            
        case ' ':
            // reposition everything:
            for (int i = 0; i < particles.size(); i++){
                particles[i].setInitialCondition(ofRandom(0,ofGetWidth()),ofRandom(0,ofGetHeight()),0,0);
            }
            break;
    }
    
    
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    particles[0].pos.set(mouseX, mouseY);
    /*particles.erase(particles.begin());
     particle myParticle;
     myParticle.setInitialCondition(x,y,0,0);
     particles.push_back(myParticle);*/
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    particles[0].bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
    
    particles[0].bFixed = false;
}

