//
//  SpringJoint.h
//  Spring_Organism
//
//  Created by Annelie Koller on 10/5/14.
//
//

#ifndef __Spring_Organism__SpringJoint__
#define __Spring_Organism__SpringJoint__

#include "ofMain.h"

class particle
{
public:
    
    ofPoint pos;
    ofPoint vel;
    ofPoint frc;   // frc is also know as acceleration (newton says "f=ma")
    
    particle();
    virtual ~particle(){};
    
    void resetForce();
    void addForce(float x, float y);
    void addRepulsionForce(float x, float y, float radius, float scale);
    void addAttractionForce(float x, float y, float radius, float scale);
    
    void addRepulsionForce(particle &p, float radius, float scale);
    void addAttractionForce(particle &p, float radius, float scale);
    void addClockwiseForce(particle &p, float radius, float scale);
    void addCounterClockwiseForce(particle &p, float radius, float scale);
    
    
    void addDampingForce();
    
    void setInitialCondition(float px, float py, float vx, float vy);
    void update();
    void draw();
    
    void bounceOffWalls();
    
    bool  bFixed;
    
    float damping;
    
protected:
private:
};
#endif /* defined(__Spring_Organism__SpringJoint__) */
