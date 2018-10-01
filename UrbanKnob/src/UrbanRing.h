#pragma once

#include "ofMain.h"


class UrbanRing;

typedef std::shared_ptr<UrbanRing> UrbanRingRef;

class UrbanRing{
public:
    static UrbanRing create(){
        return std::make_shared<UrbanRing>();
    }

private:



};
