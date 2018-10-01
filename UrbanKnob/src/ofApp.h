#pragma once

#include "ofMain.h"

//addons
#include "ofxBox2d.h"

//files
#include "UrbanKnob.h"
#include "GuiKnob.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);



		//particle physics
		ofxBox2d        box2d;   // the box2d world
		std::vector     <std::shared_ptr<ofxBox2dCircle> > circles; // default box2d circles
		bool					  mEnableParticles;

		UrbanKnobRef 	mUrbanKnob;


		ofFbo 			mBackgroundAlpha;


};
