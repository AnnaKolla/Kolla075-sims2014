#include "ofApp.h"

/* cylinder mesh example by kyle macdonald! Thank you!*/
/**
 *
 * OFDevCon Example Code Sprint
 * Model Distort Example
 
 *
 * Created by James George for openFrameworks workshop at Waves Festival Vienna sponsored by Lichterloh and Pratersauna
 * Adapted during ofDevCon on 2/23/2012
 */

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofSetFrameRate(60);
    
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    ofBackground(50, 50, 50, 0);
    //we need to call this for textures to work on models
       ofDisableArbTex();
    ofLoadImage(heightMap, "heightmap.png");
    normalFbo.allocate(ofGetWidth(), ofGetHeight());
      ofEnableArbTex();
    
    normalShader.load("","normal.frag");
    terrainShader.load("terrain");
    
 
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    
    int rings = 32, resolution = 32;
    
    float length = 512, maxRadius = 256;
    
    for(int i = 0; i < rings; i++) {
        
        float radius = ofNoise(i / 5.) * maxRadius;
        
        ofVec3f offset(0, 0, ofMap(i, 0, rings, -length, length) / 2);
        
        
        for(int j = 0; j < resolution; j++) {
            
            float theta = ofMap(j, 0, resolution, 0, 360); //j/PI * 32;
            
            ofVec2f cur(radius, 0);
            
            cur.rotate(theta);
            
            mesh.addVertex(offset+cur);
            
            mesh.addColor(ofFloatColor((i * j) % 2 == 0 ? 255 : 0));
            
//            mesh.addVertex(offset+cur);
//            mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
            
            
        }
    }
    
    for(int i = 0; i < rings - 1; i++) {
        for(int j = 0; j < resolution; j++) {
            int sw = i * resolution + j, se = sw + 1;
            if(j + 1 == resolution) {
                se -= resolution;
            }
            
            int nw = sw + resolution, ne = se + resolution;
            mesh.addTriangle(sw, se, nw);
            mesh.addTriangle(nw, se, ne);
            mesh.addTriangle(nw, sw, se);
        }
    }
    
    	light.enable();
}


//--------------------------------------------------------------
void ofApp::update(){
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
    
    
    cam.begin();
    glEnable(GL_DEPTH_TEST);
    ofSetColor(255);
    ofRotateY(90);
    mesh.draw();
    
    
    
    //modify mesh with some noise
    float liquidness = 10;
    float amplitude = mouseY/100.0;
    float speedDampen = 5;
    vector<ofVec3f>& verts = mesh.getVertices();
    for(unsigned int i = 0; i < verts.size(); i++){
        verts[i].x += ofSignedNoise(verts[i].x/liquidness, verts[i].y/liquidness,verts[i].z/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        verts[i].y += ofSignedNoise(verts[i].z/liquidness, verts[i].x/liquidness,verts[i].y/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        verts[i].z += ofSignedNoise(verts[i].y/liquidness, verts[i].z/liquidness,verts[i].x/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
    }
    

    
    ofPopMatrix();
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
