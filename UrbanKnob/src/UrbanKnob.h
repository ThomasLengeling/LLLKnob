#pragma once

#include "ofMain.h"
#include "GuiKnob.h"


class UrbanKnob;

typedef std::shared_ptr<UrbanKnob> UrbanKnobRef;

class UrbanKnob{
public:
    static UrbanKnobRef create(){
        return std::make_shared<UrbanKnob>();
    }

    void setup();

    void draw();
    void update();

    void incDraw();

    void toogleContour(){mEnableContour = !mEnableContour;}
    void toogleCenter(){mEnableCenter = !mEnableCenter;}

    //set draw center position
    void setPosition(glm::vec2 pos);
    void setRigs(float inner, float outer);

     void setvalue(float innerValue, float outerValue);

private:

    glm::vec2 mCenterPos;

    float mInnerRad;
    float mOuterRad;

    GuiKnobRef  	mInnerKnob;
    GuiKnobRef  	mOuterKnob;

    //draw enables
    int mDrawType;
    bool mEnableContour;
    bool mEnableCenter;
};
