//
//  Bees.hpp
//  Bees
//
//  Created by Miguel A Hidalgo on 11/28/17.
//

#pragma once
#include "ofMain.h"

class Bee {
public:
    
    void setup(ofImage& beeImage);
    void update(ofPoint attractor, vector<Bee>& bees);
    void canvas();
    void draw();
    
    ofImage img;
    ofPoint pos;
    ofPoint lastPos;
    ofPoint vel;
    
    float angle;
    float friction = 0.9;
};

