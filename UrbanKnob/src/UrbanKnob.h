#pragma once

#include "ofMain.h"


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

    //set draw center position
    void setPosition(glm::vec2 pos);
    void setRigs(float inner, float outer);

private:

    glm::vec2 mCenterPos;

    float mInnerRad;
    float mOuterRad;


};
