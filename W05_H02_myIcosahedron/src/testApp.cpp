#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofColor color(255, 0, 0); float hue = 254.f;
    
    //Here�s where we finally add all the vertices to our mesh and add a color at each vertex:
    for (int i = 0; i<12; ++i)
    {
        mesh.addVertex( ofVec3f( vdata[i][0], vdata[i][1], vdata[i][2] ));
        mesh.addColor(color);
        color.setHue( hue );
        hue -= 20.f;
    }
    
    for (int i = 0; i<20; ++i)
    {
        mesh.addIndex(indices[i][0]);
        mesh.addIndex(indices[i][1]);
        mesh.addIndex(indices[i][2]);
    }
}



//--------------------------------------------------------------
void testApp::update(){
    
  
        ang+=0.1;   

}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofBackground(122,122,122);
    ofPushMatrix();
    ofTranslate(400, 400, 0);
    ofRotate(ang, 1.0, 1.0, 1.0);
    //Now it�s time to draw the mesh. The ofMesh has three drawing methods: drawFaces(),
    //which draws all the faces of the mesh filled; drawWireframe(), which draws lines
    //along each triangle; and drawVertices(), which draws a point at each vertex.
    //Since we want to see the colors we�re drawing, we�ll draw all the faces:
    mesh.drawFaces();
    ofPopMatrix();
}

//--------------------------------------------------------------
