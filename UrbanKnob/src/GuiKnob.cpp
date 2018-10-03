#include "GuiKnob.h"

//--------------------------------------------------------------
GuiKnob::GuiKnob(){
  mRad = 50;
  mNumDiv = 10;

  //mLines
  mLines.clear();
  mLineBez.clear();

  mPos = glm::vec2(ofGetWidth() / 2.0, ofGetHeight() / 2.0);

  for(int i = 0; i < mNumDiv*10; i++){
    float angle = ofMap(i, 0, mNumDiv*10, 0, TWO_PI);
    float cx = cos( angle )*mRad + mPos.x;
    float cy = sin( angle )*mRad + mPos.y;
    ofVec2f vertex(cx, cy);
    mLines.addVertex(cx, cy, 0);
  }

  //colors changes
  mCurrentId = 0;

  mIndicator = GuiIndicator::create();

}


//--------------------------------------------------------------
void GuiKnob::setRad(float rad){
  mRad = rad;
}

//--------------------------------------------------------------
void GuiKnob::draw(){

    int alpha = 40;

    //draw circumference
    ofSetColor(255, alpha);
    ofNoFill();
    ofDrawCircle(mPos, mRad);

    ofSetColor(255, alpha);
    ofNoFill();
    ofDrawCircle(mPos, mRad + 20*2);

    ofFill();

    //draw line
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

void GuiKnob::drawBlobPath(){
  ofSetColor(100, 210, 255, 100);
  mLines.draw();
}

//--------------------------------------------------------------------------------
void GuiKnob::drawBlob(){

  ofMesh theMesh;
  ofTessellator tess;

  // convert poly to mesh
  ofSetColor(mIndicator->getCurrColor());
  tess.tessellateToMesh(mLines, ofPolyWindingMode::OF_POLY_WINDING_ODD, theMesh, true);
  theMesh.draw();
}

void GuiKnob::drawCenter(){
  ofSetColor(0);
  ofDrawCircle(mPos, mRad);
}

//--------------------------------------------------------------------------------
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
    arcPath.setFillColor(mIndicator->getCurrColor());
    arcPath.setFilled(true);
    arcPath.draw();
}
//--------------------------------------------------------------------------------
void GuiKnob::drawIndictor(float x, float y){

  ofSetColor(255);
  ofDrawBitmapString(mIndicator->getCurrTag(), x, y + 15);
  ofDrawBitmapString(mIndicator->getCurrId(), x + 150, y + 15);

  ofSetColor(mIndicator->getCurrColor());
  ofDrawRectangle(glm::vec2(x + 180, y), 30, 30);
}

void GuiKnob::drawRotation(){

  for(int i = 0; i < mNumDiv; i++){
    float  divAngle = 360.0 / mNumDiv;
    float  angleStart = i*divAngle;
    float  angleEnd   = angleStart + divAngle;

    float arcRadius = mRad - 20;
    float lineWidth = 40;


    ofPath arcPath;
    ofPoint p = ofPoint(mPos);
    arcPath.arc(p, arcRadius, arcRadius, angleStart, angleEnd); //center, rad, rad, rad
    arcPath.arcNegative(p, arcRadius+lineWidth, arcRadius+lineWidth, angleEnd, angleStart);

    arcPath.close();
    arcPath.setCircleResolution(60);
    arcPath.setFillColor(ofColor(mIndicator->getColor(i), 3));
    if( mIndicator->getCurrId() == i){
      arcPath.setFillColor(ofColor(mIndicator->getColor(i), 255));
    }
    arcPath.setFilled(true);
    arcPath.draw();
  }

}

//---------------------------------------------------------------------------------
void GuiKnob::setvalue(float range)
{
  //value between 0 and 1
  mRange = range;

  //update the current indicator based on the input value
  mCurrentId = int(ofClamp(range * (mNumDiv - 1), 0, 9));
  mIndicator->setCurrentId(mCurrentId);

  //
  int maxNums =  mNumDiv*10;
  int lineRange = int(range *  maxNums);
  mLines.clear();
  mLineBez.clear();

  for(int i = 0; i < maxNums; i++){
    float angle = ofMap(i, 0, maxNums, 0, TWO_PI);
    float cx = cos( angle )*mRad + mPos.x;
    float cy = sin( angle )*mRad + mPos.y;
    if(i > lineRange + 4 && i < lineRange + 9){
       cx = cos( angle )*(mRad*1.55) + mPos.x;
       cy = sin( angle )*(mRad*1.55) + mPos.y;
    }

    if( ofRandom(0, 1) > 0.95){
      cx = cos( angle )*(mRad*1.05) + mPos.x;
      cy = sin( angle )*(mRad*1.05) + mPos.y;
    }


    mLines.addVertex(glm::vec3(cx, cy, 0));
  }

  bool isClosed = true;
  mLines = mLines.getSmoothed(5);
  mLines.simplify(0.5f);

  mLineBez = ofxPathFitter::simplify(mLines, true, 1);

  ofPolyline newDisplayLine;
  newDisplayLine.addVertex(mLineBez.front().point);

  for (int i = 1; i < mLineBez.size(); i++) {
    BezPoint p1 = mLineBez[i - 1].handlesAbsolute();
    BezPoint p2 = mLineBez[i].handlesAbsolute();
    newDisplayLine.bezierTo(p1.handleOut, p2.handleIn, p2.point);
  }

  if (isClosed) {
    newDisplayLine.close();
    BezPoint p1 = mLineBez.back().handlesAbsolute();
    BezPoint p2 = mLineBez[0].handlesAbsolute();
    newDisplayLine.bezierTo(p1.handleOut, p2.handleIn, p2.point);
  }

  mLines = newDisplayLine;
}

//--------------------------------------------------------------
void GuiKnob::setPosition(glm::vec2 pos){
  mPos = pos;
}
