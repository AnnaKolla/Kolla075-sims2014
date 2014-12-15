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
    
    ofSetVerticalSync(true);
    
    ofSetFrameRate(60);
    ofDisableArbTex();
    ofLoadImage(heightMap,"coral.jpg");
    normalFbo.allocate(ofGetWidth(), ofGetHeight());
    ofEnableArbTex();
    
    normalShader.load("","normal.frag");
    terrainShader.load("terrain");
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    
    int rings = 32, resolution = 32;
    float length = 512, maxRadius = 128;

    for(int i = 0; i < rings; i++) {
        
        float radius = ofNoise(i / 5.) * maxRadius;
        
        ofVec3f offset(0, 0, ofMap(i, 0, rings, -length, length) / 2);
        
        for(int j = 0; j < resolution; j++) {
            float theta = ofMap(j, 0, resolution, 0, 360); //j/PI * 32;
            
            ofVec2f cur(radius, 0);
            
            cur.rotate(theta);
            
            mesh.addColor(j*255);
            mesh.addVertex(offset + cur*2);
            
            
          
        
            
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
            
            int t = (i+j*resolution);
            int n = resolution - 1;
            int m = resolution + 1;
            
            mesh.addTexCoord(ofPoint(t % 2 == 0 ? 0 : rings ));
            mesh.addTexCoord(ofPoint(rings % 2 == 0 ? 0 : n ));
            mesh.addTexCoord(ofPoint(rings % 2 == 0 ? 0 : m ));
            
            mesh.addNormal(ofPoint(1,0,0));
            

             if(j%2==0){
            mesh.addIndex(j+i*resolution);				// a
            mesh.addIndex((j+1)+i*resolution);			// b
            mesh.addIndex(j+(i+1)*resolution);			// d
            
            mesh.addIndex((j+1)+i*resolution);			// b
            mesh.addIndex((j+1)+(i+1)*resolution);		// c
            mesh.addIndex(j+(i+1)*resolution);			// d
             }else{
            mesh.addIndex((j+1)+i*resolution);			// b
            mesh.addIndex(j+i*resolution);				// a
            mesh.addIndex((j+1)+(j+1)*resolution);		// c
            
            mesh.addIndex(j+i*resolution);				// a
            mesh.addIndex(j+(i+1)*resolution);			// d
            mesh.addIndex((j+1)+(i+1)*resolution);		// c
             }

        }

    }

    
    light.enable();
    bWireframe = true;
}


//--------------------------------------------------------------
void ofApp::update(){

    int width = ofGetWidth();
    int height = ofGetHeight();
    
    //  Compute the normals inside a FBO
    //  a FBO is like a screen... we can render and draw in it.
    //  but instead of been render on the monitor is render into memory (Frame Buffer Object)
    //  That have a texture that then we will pass to the vertex/frag shader that creates the terrain
    //
    normalFbo.begin();
    ofClear(0);
    ofSetColor(255);
    normalShader.begin();
    normalShader.setUniformTexture("texture", heightMap,0);
    glBegin(GL_QUADS);
    
    glTexCoord2f(0, 0);
    glVertex2f(0, 0);
    
    glTexCoord2f(1.0, 0);
    glVertex2f(width, 0);
    
    glTexCoord2f(1.0, 1.0);
    glVertex2f(width, height);
    
    glTexCoord2f(0, 1.0);
    glVertex2f(0, height);
    
    glEnd();
    normalShader.end();
    normalFbo.end();
    
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
 
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    

    ofBackground(0);
    
    // Camera!
    cam.begin();
    
    // Action!
    ofPushMatrix();
    
    //  Center the mesh;
   ofTranslate(-ofGetWidth()*0.5, -ofGetHeight()*0.5);
    
    //  Draw the mesh applying the shader that will move the points to different height
    //  acording to the texture
    //
    terrainShader.begin();
    terrainShader.setUniformTexture("heightMap", heightMap,0);
    terrainShader.setUniformTexture("normalMap", normalFbo,1);

    terrainShader.setUniform1f("time",ofGetElapsedTimef());     // We can play with this later ;)
    
    if(bWireframe){
        mesh.drawWireframe();
    } else {
            mesh.draw();
    }
    
    terrainShader.end();
    
    ofPopMatrix();
    
    cam.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'w'){
        bWireframe = !bWireframe;
    } else {
        terrainShader.load("terrain");
    }
}

