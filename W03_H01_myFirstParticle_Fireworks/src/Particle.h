//
//  Particle.h
//  myFirstParticle_1
//
//  Created by Annelie Koller on 9/29/14.
//
//

#ifndef __myFirstParticle_1__Particle__
#define __myFirstParticle_1__Particle__

#include <iostream>

#import "ofMain.h"

class Particle {

    public:
    
    Particle();
    	virtual ~Particle(){};
    
    void resetForce();
	void addForce(float x, float y);
	void addDampingForce();
	void setInitialCondition(float px, float py, float vx, float vy);
	void update();
	void draw();
    
    ofPoint pos;
	ofPoint vel;
	ofPoint frc;
    ofPoint center;

    
    float damping;
	
	int alpha;
    
    int r, g, b;
	float size;
    
//    int trailSize;
//
//    vector <myFireworkst> trail;
    
     private:
    

};

#endif /* defined(__myFirstParticle_1__Particle__) */
