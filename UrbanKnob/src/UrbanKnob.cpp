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

  //draw types
  mDrawType = 0;
  mEnableContour = false;
  mEnableCenter  = false;
}

void UrbanKnob::incDraw(){
  mDrawType++;
  if(mDrawType >= 8){
    mDrawType = 0;
  }
}

//--------------------------------------------------------------
void UrbanKnob::draw() {

  //draw indicators values
  mOuterKnob->drawIndictor(20, 30);
  mInnerKnob->drawIndictor(20, 80);


  if(mEnableContour){
    mOuterKnob->draw();
    mInnerKnob->draw();
  }

  if(mDrawType == 1){
    mOuterKnob->draw();
    mInnerKnob->draw();
  }

  if(mDrawType == 2){
    mOuterKnob->drawArc();
    mInnerKnob->drawArc();
  }

  if(mDrawType == 3){
    mOuterKnob->drawBlobPath();
    mInnerKnob->drawBlobPath();
  }
  if(mDrawType == 4){
    mOuterKnob->drawArc();
    mInnerKnob->drawArc();

    mOuterKnob->drawBlobPath();
    mInnerKnob->drawBlobPath();
  }

  if(mDrawType == 5){
    mOuterKnob->drawBlob();
    mInnerKnob->drawBlob();
  }
  if(mDrawType == 6){
    mOuterKnob->drawBlobPath();
    mOuterKnob->drawBlob();
    if(mEnableCenter){
      mOuterKnob->drawCenter();
    }

    mInnerKnob->drawBlobPath();
    mInnerKnob->drawBlob();
    if(mEnableCenter){
      mInnerKnob->drawCenter();
    }
  }

  if(mDrawType == 7 ){
    mOuterKnob->drawRotation();
    mInnerKnob->drawRotation();
  }

  if(mEnableCenter && mDrawType != 6){
    mOuterKnob->drawCenter();
    mInnerKnob->drawCenter();
  }

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
