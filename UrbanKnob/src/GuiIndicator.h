#pragma once

#include "ofMain.h"
#include "CommonTypes.h"


typedef struct Indicator{
  ofColor color;
  int index;
  std::string tag;
  bool enable;
}Indicator;


//----------------------------------------------------------------------------
class GuiIndicator;
typedef std::shared_ptr<GuiIndicator> GuiIndicatorRef;

class GuiIndicator{
public:

    GuiIndicator();

    static GuiIndicatorRef create(){
        return std::make_shared<GuiIndicator>();
    }

    ofColor getColor(int id){return mIndicator.at(id).color;}
    std::string getTag(int id){return mIndicator.at(id).tag;}
    int getId(int id){return mIndicator.at(id).index;}
    void toggle(int id){mIndicator.at(id).enable = !mIndicator.at(id).enable;}

    ofColor getCurrColor(){return mIndicator.at(mCurrentId).color;}
    std::string getCurrTag(){return mIndicator.at(mCurrentId).tag;}
    int getCurrId(){return mIndicator.at(mCurrentId).index;}
    void toggleCurr(){mIndicator.at(mCurrentId).enable = !mIndicator.at(mCurrentId).enable;}

    void setCurrentId(int id){mCurrentId = id;}
private:

  //curent idex of the rotation
  Indicator mCurrentInd;
  int mCurrentId;

  //values
  std::vector<Indicator>     mIndicator;
};
