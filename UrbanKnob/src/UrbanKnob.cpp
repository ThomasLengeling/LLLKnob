#include "UrbanKnob.h"

void UrbanKnob::setup() {}

//--------------------------------------------------------------
void UrbanKnob::draw() {
  ofSetColor(0, 155, 150);
  ofDrawCircle(mCenterPos, mOuterRad);

  // display rotation of the circle

  ofSetColor(50, 155, 250);
  ofDrawCircle(mCenterPos, mInnerRad);

  // display rotation of the circle.

  // marker
  ofSetColor(50, 50, 50);
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
