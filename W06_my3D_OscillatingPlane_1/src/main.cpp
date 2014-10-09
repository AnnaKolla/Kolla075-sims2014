
#include "ofApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){
    
    ofAppGlutWindow window;
	ofSetupOpenGL(1024,768,OF_WINDOW);
	
	ofRunApp(new ofApp());

}
