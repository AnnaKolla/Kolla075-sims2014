#include "testApp.h"
//#include "ofMain.h"

//--------------------------------------------------------------
void testApp::setup(){
  
    
    for( int i=0; i<11; i++ ){
        
        SpringJoint sj;
        sj.pos = ofPoint(ofGetWindowWidth()/2, 10 + i*155);
        jointList.push_back( sj );
    }
    
    
    Spring spring1, spring2, spring3, spring4, spring5, spring6, spring7, spring8, spring9, spring10, spring11, spring12;
    
    spring1.set( &jointList[0], &jointList[1], 0.05, 200.0 );
    spring2.set( &jointList[5], &jointList[6], 0.05, 200.0 );
    spring3.set( &jointList[1], &jointList[2], 0.05, 200.0 );
    spring4.set( &jointList[4], &jointList[5], 0.05, 200.0 );
    spring5.set( &jointList[2], &jointList[3], 0.05, 200.0 );
    spring6.set( &jointList[3], &jointList[4], 0.05, 200.0 );
    spring7.set( &jointList[3], &jointList[4], 0.05, 200.0 );
    spring8.set( &jointList[2], &jointList[3], 0.05, 200.0 );
    spring9.set( &jointList[4], &jointList[5], 0.05, 200.0 );
    spring10.set( &jointList[1], &jointList[2], 0.05, 200.0 );
    spring11.set( &jointList[5], &jointList[6], 0.05, 200.0 );
    
    spring12.set( &jointList[6], &jointList[0], 0.05, 200.0 );
    
    
    springList.push_back( spring1 );
    springList.push_back( spring2 );
    springList.push_back( spring3 );
    springList.push_back( spring4 );
    springList.push_back( spring5 );
    springList.push_back( spring6 );
    springList.push_back( spring7 );
    springList.push_back( spring8 );
    springList.push_back( spring9 );
    springList.push_back( spring10 );
    springList.push_back( spring11 );
    springList.push_back( spring12 );
    
    
    bDragging = false;
    
    ofSetFrameRate(60.0);
    ofSetVerticalSync( true );
    ofBackground(0);
    
//    for (int i = 0; i < numXeno; i++){
//        
//        myBall[i].catchUpSpeed = (i+1)*0.03f;
//        
//        myBall[i].pos.x = 30*i;
//        myBall[i].pos.y = 30*i;
//        myBall[i].xenoR = 60 - (5*i);
//        
//        
//        
//    }
}

/**
 *  We're working with Hookes law here http://en.wikipedia.org/wiki/Hooke's_law
 *  F = -k * x;
 */

//--------------------------------------------------------------
void testApp::update(){
    
    if( bDragging ){
        return;
    }
    
    for( int i=0; i<springList.size(); i++ ){
        springList[i].update();
    }
    
    for( int i=0; i<jointList.size(); i++ ){
       jointList[i].update();
    }
    
//    
//    for (int i =0; i < numXeno; i++){
//        
//        SpringJoint sj;
//        
//        sj.pos =  ofVec2f(ofGetWindowWidth()/2, 10 + i*195);
//        //pos.y =  ofVec2f(ofGetWindowHeight()/2, 10 + i*195);
//        
//        //myBall[i].xenoToPoint(pos);
//        
//        jointList.push_back( sj );
//        
//    }
}

//--------------------------------------------------------------
void testApp::draw(){
 
    
    for( int i=0; i<springList.size(); i++ ){
        springList[i].draw();
    }
    
    for( int i=0; i<jointList.size(); i++ ){
        jointList[i].draw();
        
      
   }
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
    int rand = floor( ofRandom( jointList.size() ) );
    
    jointList[rand].applyForce( ofVec2f(ofRandom(-10, 10), 0) );
//    jointList[1].applyForce( ofVec2f(ofRandom(-5, 5), 0) );
//    jointList[2].applyForce( ofVec2f(ofRandom(-1, 1), 0) );
//    jointList[3].applyForce( ofVec2f(ofRandom(-5, 5), 0) );
//    jointList[4].applyForce( ofVec2f(ofRandom(-10, 10), 0) );
//    jointList[5].applyForce( ofVec2f(ofRandom(-5, 5), 0) );
//    jointList[6].applyForce( ofVec2f(ofRandom(-1, 1), 0) );
//    jointList[7].applyForce( ofVec2f(ofRandom(-5, 5), 0) );
//    jointList[8].applyForce( ofVec2f(ofRandom(-10, 10), 0) );
//    jointList[9].applyForce( ofVec2f(ofRandom(-5, 5), 0) );
//    jointList[10].applyForce( ofVec2f(ofRandom(-1, 1), 0) );
//    jointList[11].applyForce( ofVec2f(ofRandom(-5, 5), 0) );
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
    
    bDragging = false;
    
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
