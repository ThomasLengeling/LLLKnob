#include "GuiKnob.h"


void GuiKnob::setRad(float rad){
  mRad = rad;
}

//--------------------------------------------------------------
void GuiKnob::draw(){

    int alpha = 40;

    ofSetColor(255, alpha);
    ofNoFill();
    ofDrawCircle(mPos, mRad);

    ofSetColor(255, alpha);
    ofNoFill();
    ofDrawCircle(mPos, mRad + 20*2);





    ofSetColor(255, alpha);

    float px = cos(mRange*TWO_PI);
    float py = sin(mRange*TWO_PI);
    ofVec2f end(mPos + mRad*ofVec2f(px, py) );
    ofVec2f start(mPos + mRad*ofVec2f(px, py)*0.6 );
    ofDrawLine(start, end);

}

void GuiKnob::drawCircle(){
  ofFill();

  ofSetColor(50, 155, 250);
  ofDrawCircle(mPos, mRad);

  ofSetColor(0);
  ofDrawCircle(mPos, mRad*0.6);
}

void GuiKnob::drawArcPath(){

}

//--------------------------------------------------------------
void GuiKnob::drawArc(){
    float  angleStart = mRange*360;
    float  angleEnd   = angleStart + (360.0/mNumDiv);

    float arcRadius = mRad - 20*2;
    float lineWidth = 40 * 2;


    ofPath arcPath;
    ofPoint p = ofPoint(mPos);
    arcPath.arc(p, arcRadius, arcRadius, angleStart, angleEnd); //center, rad, rad, rad
    arcPath.arcNegative(p, arcRadius+lineWidth, arcRadius+lineWidth, angleEnd, angleStart);

    arcPath.close();
    arcPath.setCircleResolution(60);
    arcPath.setFillColor(ofColor(100, 210, 255, 200));
    arcPath.setFilled(true);
    arcPath.draw();
}

//--------------------------------------------------------------
void GuiKnob::setvalue(float range)
{
  //value between 0 and 1

  mRange = range;
}

//--------------------------------------------------------------
void GuiKnob::setPosition(glm::vec2 pos){
  mPos = pos;
}
