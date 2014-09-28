#pragma once

#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "Ball.h"


//---------------------------------------------
class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

private:
    
    Ball** myBall;
    int nBalls;
    

};

#endif