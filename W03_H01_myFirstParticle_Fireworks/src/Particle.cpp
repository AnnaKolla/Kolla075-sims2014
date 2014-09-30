//
//  Particle.cpp
//  myFirstParticle_1
//
//  Created by Annelie Koller on 9/29/14.
//
//

#include "Particle.h"
#include "ofMain.h"

Particle::Particle(){
    
    setInitialCondition(center.x, center.y, ofRandom(-3, 3), ofRandom(-3, 3));
    
	damping = 0.001f;
	
    
	alpha = 1;
	size = 3.5;
    //trailSize = .02;

    
}

//------------------------------------------------------------
void Particle::resetForce(){
    frc.set(0, 0);
}

//------------------------------------------------------------
void Particle::addForce(float x, float y){
    
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void Particle::addDampingForce(){
    
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void Particle::setInitialCondition(float px, float py, float vx, float vy){
    
    pos.set(px, py);
    vel.set(vx, vy);
}

//------------------------------------------------------------
void Particle::update(){
    
    pos = pos + vel;
    vel = vel + frc;
    
    alpha+=5;
	
	
	if (alpha==500) {
		alpha=0;
	}
   
}

//------------------------------------------------------------

void Particle::draw(){
    
    
	
	ofEnableAlphaBlending();
    
    r = ofRandom(1,255);
    g = ofRandom(1,255);
    b = ofRandom(1,255);
    
	alpha = ofRandom(90,100);
	
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    ofSetColor(r, g, b, alpha);
    
    ofCircle(pos.x, pos.y, 3);
	
	ofDisableAlphaBlending();
}




