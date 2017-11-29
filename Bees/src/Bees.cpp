//
//  Bee.cpp
//  Bees
//
//  Created by Miguel A Hidalgo on 11/28/17.
//


#include "Bees.hpp"


// --------------------------------------------------------------
void Bee::setup(ofImage& beeImage) {
    img = beeImage;
    pos.x = ofRandomWidth();
    pos.y = ofRandomHeight();
    vel.x = ofRandom(-10, 10);
    vel.y = ofRandom(-10, 10);
}

// --------------------------------------------------------------
void Bee::update(ofPoint attractor, vector<Bee>& bees) {
    ofPoint acc;
    
    float dist = pos.distance(attractor);
    if(dist < 300) {
        ofPoint dir = attractor - pos;
        dir.normalize();
        
        float force = ofMap(dist, 5, 300, 0, 20);
        acc = dir * force;
    }
    
    for(int i=0; i<bees.size(); i++)
    {
        float dist = pos.distance(bees[i].pos);
        if(dist>0 && dist < 20) {
            ofPoint dir = pos - bees[i].pos;
            dir.normalize();
            float force = ofMap(dist, 0, 20, 0, 100);
            acc = dir * force;
        }
    }
    
    vel += acc;
    vel.limit(10);
    pos += vel;
    canvas();
    
    vel *= friction;
    
    if(pos.distance(lastPos) > 1) {
        angle =  atan2(lastPos.y - pos.y, lastPos.x - pos.x);
    }
    lastPos = pos;
}

// --------------------------------------------------------------
void Bee::canvas() {
    if(pos.x > ofGetWidth()+20) {
        pos.x = -20;
    }
    if(pos.y > ofGetHeight()+20) {
        pos.y = -20;
    }
    if(pos.x < -20) {
        pos.x = ofGetWidth()+20;
    }
    if(pos.y < -20) {
        pos.y = ofGetHeight()+20;
    }
}

// --------------------------------------------------------------
void Bee::draw() {
    ofPushMatrix();
    ofTranslate(pos.x, pos.y);
    ofRotate(ofRadToDeg(angle)-90);
    ofScale(0.2, 0.2);
    ofSetColor(255);
    img.draw(-img.getWidth()/2.0, -img.getHeight()/2.0);
    ofPopMatrix();
}
