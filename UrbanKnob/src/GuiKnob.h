#pragma once

#include "ofMain.h"
#include "ofxPathFitter.h"
#include "CommonTypes.h"
#include "GuiIndicator.h"

class GuiKnob;

typedef std::shared_ptr<GuiKnob> GuiKnobRef;

class GuiKnob{
public:

    GuiKnob();

    static GuiKnobRef create(){
        return std::make_shared<GuiKnob>();
    }

    void draw();
    void drawArc();
    void drawCircle();

    void drawBlobPath();
    void drawBlob();

    void drawCenter();
    void drawRotation();

    void drawIndictor(float x, float y);

    void setRad(float rad);
    void setPosition(glm::vec2 pos);

    void setvalue(float range);


private:

  //position of the knob
  glm::vec2   mPos;

  // size of the knob
  float       mRad;

  //number of divisions of the knob
  int         mNumDiv;

  //range of change
  float       mRange;

  //values to stop min and max
  ofVec2f     mRangeStop;

  //poly line
  ofPolyline  mLines;
  vector<BezPoint> mLineBez;

  //curent idex of the rotation
  int mCurrentId;

  GuiIndicatorRef mIndicator;

};
