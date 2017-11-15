
//  snowParticles.hpp
//  Particles
//
//  Created by Miguel A Hidalgo on 10/17/17.
//

#ifndef snowParticles_hpp
#define snowParticles_hpp

#include "ofMain.h"


class snowParticles
{
public:
    
    void setupMe() {
        //Position & Velocity
        pos.set(ofRandom(0, ofGetWindowWidth()), ofRandom(-ofGetWindowHeight(), ofGetWindowHeight()));
        vel.set(ofRandom(-0.08, 0.08), ofRandom(0.01, 0.5)); // x y
        //Color
        col.r = 190;
        col.g = 200;
        col.b = 255;
        col.a = ofRandom(100,150);
        // Radius
        radius = ofRandom(1,3);
    }
    
    void updateMe() {
        //Speed
        pos += vel;
    }
    
    void drawMe() {
        //Snow Particles
        ofSetColor(col);
        ofDrawCircle(pos, radius);
    }
    
    ofPoint pos;
    ofPoint vel;
    ofColor col;
    int radius;
    
};


#endif /* snowParticles_hpp */
