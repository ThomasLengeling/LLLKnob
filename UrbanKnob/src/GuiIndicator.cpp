#include "GuiIndicator.h"

//----------------------------------------------------------------------------
GuiIndicator::GuiIndicator(){

  mCurrentId = 0;
  
  {
    Indicator ind;
    ind.index  = 0;
    ind.color  = ofColor::fromHex(RS);
    ind.tag    = "Residential Small";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 1;
    ind.color  = ofColor::fromHex(RM);
    ind.tag    = "Residential Meidum";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 2;
    ind.color  = ofColor::fromHex(RL);
    ind.tag    = "Residential Large";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 3;
    ind.color  = ofColor::fromHex(OS);
    ind.tag    = "Office Small";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 4;
    ind.color  = ofColor::fromHex(OM);
    ind.tag    = "Office Medium";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 5;
    ind.color  = ofColor::fromHex(OL);
    ind.tag    = "Office Large";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 6;
    ind.color  = ofColor::fromHex(ES_0);
    ind.tag    = "Especial 00";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 7;
    ind.color  = ofColor::fromHex(ES_1);
    ind.tag    = "Especial 01";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 8;
    ind.color  = ofColor::fromHex(ES_2);
    ind.tag    = "Especial 02";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

  {
    Indicator ind;
    ind.index  = 9;
    ind.color  = ofColor::fromHex(ES_3);
    ind.tag    = "Especial 03";
    ind.enable = false;
    mIndicator.push_back(ind);
  }

}
