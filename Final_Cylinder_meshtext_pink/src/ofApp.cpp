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
    ofBackground(50, 0, 0);
    ofDisableArbTex();
    glEnable(GL_DEPTH_TEST);
    ofSetFrameRate(60);
    
    glMatrixMode(GL_PROJECTION);
     glEnable(GL_TEXTURE_2D);
    
    colormap.loadImage("coral.jpg");
    bumpmap.loadImage("coralbw.jpg");
        
    
//    quadric = gluNewQuadric();
//    gluQuadricTexture(quadric, GL_TRUE);
//    gluQuadricNormals(quadric, GLU_SMOOTH);
    
    shader.load("displace.vert", "displace.frag");
    
    //we need to call this for textures to work on models
    
    mesh.setMode(OF_PRIMITIVE_TRIANGLES);
    
    
    int rings = 32, resolution = 32;
    float length = 512, maxRadius = 128;
    for(int i = 0; i < rings; i++) {
        
        float radius = ofNoise(i / 5.) * maxRadius;
        
        ofVec3f offset(0, 0, ofMap(i, 0, rings, -length, length) / 2);
        
        //ofVec3f offset(0, 0, ofMap(sin(i), 0, rings,-length, length)/2);
        
        for(int j = 0; j < resolution; j++) {
            
            float theta = ofMap(j, 0, resolution, 0, 360); //j/PI * 32;
            
            ofVec2f cur(radius, 0);
            
            cur.rotate(theta);
            
            //mesh.addColor(j*255);
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
            
            mesh.addTexCoord(ofPoint(sw));
            mesh.addTexCoord(ofPoint(se));
            mesh.addTexCoord(ofPoint(nw));
            mesh.addTexCoord(ofPoint(nw));
            mesh.addTexCoord(ofPoint(se));
            mesh.addTexCoord(ofPoint(ne));
            mesh.addTexCoord(ofPoint(nw));
            mesh.addTexCoord(ofPoint(sw));
            mesh.addTexCoord(ofPoint(se));
            
            //mesh.setupIndicesAuto();	//Set up indices
//            mesh.addTexCoord(ofPoint((i + j) % 2 == 0 ? 255 : 0));
//            mesh.addTexCoord(ofPoint((i + j) % 2 == 0 ? 0 : 255));
//            mesh.addTexCoord(ofPoint((i + j) % 2 == 0 ? 255 : 255));
            

            
//            mesh.addTexCoord(ofPoint(j+i*rings));				// a
//           mesh.addTexCoord(ofPoint((j+1)+i*rings));			// b
//            mesh.addTexCoord(ofPoint(j+(i+1)*rings));			// d
//            
//            mesh.addTexCoord(ofPoint((j+1)+i*rings));			// b
//            mesh.addTexCoord(ofPoint((j+1)+(i+1)*rings));		// c
//            mesh.addTexCoord(ofPoint(j+(i+1)*rings));			// d
//            
//            mesh.addTexCoord(ofPoint((j+1)+i*rings));			// b
//           mesh.addTexCoord(ofPoint(j+i*rings));				// a
//
//           mesh.addTexCoord(ofPoint(j+1)+(j+1)*rings);		// c
//            
//            mesh.addTexCoord(ofPoint(j+i*rings));				// a
//            mesh.addTexCoord(ofPoint(j+(i+1)*rings));			// d
//            mesh.addTexCoord(ofPoint((j+1)+(i+1)*rings));		// c

     }
    }

    setNormals(mesh);
    light.enable();
}


//--------------------------------------------------------------
void ofApp::update(){

  
    float time = ofGetElapsedTimef();
    float dt = ofClamp( time - time0, 0, 0.1 );
    time0 = time;
    float speed = ofMap( mouseY, 0, ofGetHeight(), 0, 5 );
    phase += speed * dt;
    distortAmount = ofMap( mouseX, 0, ofGetWidth(), 0, 1.0 );
 
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_LINEAR);
    
    ofPopMatrix();
    
    cam.begin();
    
    colormap.bind();
    bumpmap.bind();
    
    shader.begin();
    shader.setUniformTexture("colormap", colormap, 1);
    shader.setUniformTexture("bumpmap", bumpmap, 2);
    shader.setUniform1i("maxHeight",mouseX);
    
    mesh.drawWireframe();
    
    //modify mesh with some noise
    float liquidness = 10;
    float amplitude = mouseY/50.0;
    float speedDampen = 5;
    vector<ofVec3f>& verts = mesh.getVertices();
    for(unsigned int i = 0; i < verts.size(); i++){
        verts[i].x += ofSignedNoise(verts[i].x/liquidness, verts[i].y/liquidness,verts[i].z/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        verts[i].y += ofSignedNoise(verts[i].z/liquidness, verts[i].x/liquidness,verts[i].y/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
        verts[i].z += ofSignedNoise(verts[i].y/liquidness, verts[i].z/liquidness,verts[i].x/liquidness, ofGetElapsedTimef()/speedDampen)*amplitude;
    }
    
   colormap.unbind();
    bumpmap.unbind();
    shader.end();
    
    ofPopMatrix();
    
    cam.end();
}

//--------------------------------------------------------------

void setNormals( ofMesh &mesh ){
    
    //The number of the vertices
    int nV = mesh.getNumVertices();
    
    //The number of the triangles
    int nT = mesh.getNumIndices() / 3;
    
    vector<ofPoint> norm( nV );			//Array for the normals
    
    //Scan all the triangles. For each triangle add its
    //normal to norm's vectors of triangle's vertices
    for (int t=0; t<nT; t++) {
        
        //Get indices of the triangle t
        int i1 = mesh.getIndex( 3 * t );
        int i2 = mesh.getIndex( 3 * t + 1 );
        int i3 = mesh.getIndex( 3 * t + 2 );
        
        //Get vertices of the triangle
        const ofPoint &v1 = mesh.getVertex( i1 );
        const ofPoint &v2 = mesh.getVertex( i2 );
        const ofPoint &v3 = mesh.getVertex( i3 );
        
        //Compute the triangle's normal
        ofPoint dir = ( (v2 - v1).crossed( v3 - v1 ) ).normalized();
        
        //Accumulate it to norm array for i1, i2, i3
        norm[ i1 ] += dir;
        norm[ i2 ] += dir;
        norm[ i3 ] += dir;
    }
    
    //Normalize the normal's length
    for (int i=0; i<nV; i++) {
        norm[i].normalize();
    }
    
    //Set the normals to mesh
    mesh.clearNormals();
    mesh.addNormals( norm );
}



