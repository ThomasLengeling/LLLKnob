#include "UrbanKnob.h"

void UrbanKnob::setup() {



  //knobs
  mInnerKnob = GuiKnob::create();
  mInnerKnob->setRad(100);
  mInnerKnob->setPosition(glm::vec2(ofGetWidth() / 2.0, ofGetHeight() / 2.0));

  //knobs
  mOuterKnob = GuiKnob::create();
  mOuterKnob->setRad(235);
  mOuterKnob->setPosition(glm::vec2(ofGetWidth() / 2.0, ofGetHeight() / 2.0));
}

//--------------------------------------------------------------
void UrbanKnob::draw() {

  //small ring outer
  //ofSetColor(90, 200, 180, 150);
  //ofDrawCircle(mCenterPos, 220);

  //ofSetColor(0);
  //ofDrawCircle(mCenterPos, 220*0.75);


  mOuterKnob->draw();
  mOuterKnob->drawArc();

  mInnerKnob->draw();
  mInnerKnob->drawArc();

  // marker
  ofSetColor(100, 100, 100);
  ofDrawRectangle(mCenterPos.x - mInnerRad / 2.0,
                  mCenterPos.y - mInnerRad / 2.0, mInnerRad, mInnerRad);
}

//--------------------------------------------------------------
void UrbanKnob::update() {}

//--------------------------------------------------------------
void UrbanKnob::setPosition(glm::vec2 pos) {
  // // set draw center position
  mCenterPos = pos;
}

//--------------------------------------------------------------
void UrbanKnob::setRigs(float inner, float outer) {
  mOuterRad = outer;
  mInnerRad = inner;
}

void UrbanKnob::setvalue(float innerValue, float outerValue){
  mInnerKnob->setvalue(outerValue);
  mOuterKnob->setvalue(innerValue);
}
