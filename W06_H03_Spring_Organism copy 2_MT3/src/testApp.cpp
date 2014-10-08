
#include "testApp.h"


void testApp::makeSpring(particle * a, particle * b){
    
    spring mySpring;
    mySpring.distance = (a->pos - b->pos).length();
    mySpring.springiness = 0.1;
    mySpring.particleA = a;
    mySpring.particleB = b;
    
    mySpring.origDistance = mySpring.distance;
    
    springs.push_back(mySpring);
 
    
    
}


//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(true);
    ofSetCircleResolution(100);
    
    
    radius = 100;
    
    float xorig = 400;
    float yorig = 400;
    float angle = 0;
    
    particle * base = new particle();
    base->setInitialCondition(xorig, yorig, 0, 0);
    particles.push_back(base);
    
    
    for(int i = 0; i < 10; i++){
        ofSetColor(0);
        particle * myParticle = new particle();
        ofSetColor(0);
        angle = PI/10 *i;
        float x = xorig + radius * cos(angle);
        float y = yorig + radius * -sin(angle);
        myParticle->setInitialCondition(x,y,0,0);
        particles.push_back(myParticle);
        
        makeSpring(base, myParticle);
        
        for(int i = 0; i < 20; i++){
            ofSetColor(200, 0, 20);
            particle * myParticleInner = new particle();
            ofSetColor(200, 0, 20);
            float radius2 = 20;
            angle = PI/10 *i;
            float x2 = x + radius2 * cos(angle);
            float y2 = y + radius2 * -sin(angle);
            myParticleInner->setInitialCondition(x2,y2,0,0);
            particles.push_back(myParticleInner);
            
            makeSpring(myParticle, myParticleInner);
        }
    }
    
    //    for (int i = 0; i < (particles.size()-1); i++){
    //		spring * mySpring = new spring();
    //		mySpring->distance		= 25;
    //		mySpring->springiness	= 0.4f;
    //		mySpring->particleA = & (*particles[i]);
    //		mySpring->particleB = & (*particles[(i+1) % particles.size()]);
    //		springs.push_back(mySpring);
    //	}
    
    //particles[particles.size()-1].bFixed = true;
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    for (int i = 0; i < springs.size(); i++){
        springs[i].distance =  springs[i].origDistance * 4 * ofMap(sin(ofGetElapsedTimef() + i/100.0
                                                                       ), -1,1,0,1);
    }
    
    
    
    for (int i = 0; i < particles.size(); i++){
        particles[i]->resetForce();
    }
    
    
    for (int i = 0; i < particles.size(); i++){
        
        particles[i]->addRepulsionForce(mouseX, mouseY, 100, 0.05f); //x,  y,  radius, scale
        
        for (int j = 0; j < i; j++){
            particles[i]->addRepulsionForce(*particles[j], 20, 0.05f);
        }
    }
    
    for (int i = 0; i < springs.size(); i++){
        springs[i].update();
    }
    
    for (int i = 0; i < particles.size(); i++){
        particles[i]->addDampingForce();
        particles[i]->update();
    }
    
    
    
    
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(0);
    //    ofCircle(mouseX, mouseY, 3);
    
    for (int i = 0; i < particles.size(); i++){
        particles[i]->draw();
    }
    
    
    for (int i = 0; i < springs.size(); i++){
        springs[i].draw();
    }
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    radius ++;
    
    if (radius > 100) {
        radius = 100;
    }
    
    
    particles[0]->pos.set(mouseX, mouseY);
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    particles[0]->bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
    
    particles[0]->bFixed = false;
    radius = 0;
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
