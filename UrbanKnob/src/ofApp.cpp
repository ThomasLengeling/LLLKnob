#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

  ofSetBackgroundAuto(false);
  ofClear(ofColor(0, 0, 0, 255));
  ofSetVerticalSync(true);
  ofDisableAntiAliasing();
  ofSetCircleResolution(100);

  mUrbanKnob = UrbanKnob::create();
  mUrbanKnob->setup();
  mUrbanKnob->setRigs(50, 100);
  mUrbanKnob->setPosition(glm::vec2(ofGetWidth() / 2.0, ofGetHeight() / 2.0));


  //box2d
  mEnableParticles = false;

  box2d.init();
  box2d.setGravity(0, 0);
  box2d.setFPS(60.0);

  for(int i=0; i<100; i++) {
    float r = ofRandom(3);
    auto circle = std::make_shared<ofxBox2dCircle>();
    circle.get()->setPhysics(3.0, 0.53, 0.9);
    circle.get()->setup(box2d.getWorld(), ofGetWidth()/2, ofGetHeight()/2, r);
    circles.push_back(circle);
  }

  //background alpha render
  mBackgroundAlpha.allocate(ofGetWidth(), ofGetHeight(), 4);

  mBackgroundAlpha.begin();
  ofClear(ofColor(0, 0, 0, 255));
  mBackgroundAlpha.end();

}

//--------------------------------------------------------------
void ofApp::update() {

  if(mEnableParticles){
    box2d.update();
  	ofVec2f mouse(ofGetMouseX(), ofGetMouseY());
  	float minDis = ofGetMousePressed() ? 50 : 20;

  	for(int i=0; i<circles.size(); i++) {
  		float dis = mouse.distance(circles[i].get()->getPosition());
  		if(dis < minDis){
        circles[i].get()->addRepulsionForce(mouse, 1);
      }else{
        ofVec2f center(ofGetWidth() / 2.0, ofGetHeight() / 2.0);
        circles[i].get()->addAttractionPoint(center, 4.0);
      }
  	}
  }

}

//--------------------------------------------------------------
void ofApp::draw() {

  mBackgroundAlpha.begin();
  ofSetColor(0, 0, 0, 10);
  ofRect(0,0,ofGetWidth(),ofGetHeight());
  mUrbanKnob->draw();

  if(mEnableParticles){
    for(int i=0; i<circles.size(); i++) {
      ofFill();
      ofSetHexColor(0xf6c738);
      circles[i].get()->draw();
    }

    // draw the ground
    box2d.drawGround();
  }
  mBackgroundAlpha.end();


  ofSetColor(255);
  mBackgroundAlpha.draw(0, 0);


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
  if(key == 'p'){
    mEnableParticles = !mEnableParticles;
  }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
   float rangeI = ofMap(x, 0, ofGetWidth(), 0.0, 1.0);
   float rangeO = ofMap(y, 0, ofGetHeight(), 0.0, 1.0);

   mUrbanKnob->setvalue(rangeI, rangeO);

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {}
