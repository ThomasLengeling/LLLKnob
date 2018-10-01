#pragma once

#include "ofMain.h"


class GuiKnob;

typedef std::shared_ptr<GuiKnob> GuiKnobRef;

class GuiKnob{
public:

    GuiKnob(){
      mRad = 50;
      mNumDiv = 10;
    }

    static GuiKnobRef create(){
        return std::make_shared<GuiKnob>();
    }

    void draw();
    void drawArc();
    void drawCircle();
    void drawArcPath();

    void setRad(float rad);
    void setPosition(glm::vec2 pos);

    void setvalue(float range);


private:

  //position of the knob
  glm::vec2 mPos;

  // size of the knob
  float     mRad;

  //number of divisions of the knob
  int       mNumDiv;


  float     mRange;


  //values
  ofVec2f   mRangeStop;

};
