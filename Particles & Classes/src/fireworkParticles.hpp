
//  fireworkParticles.hpp
//  Particles
//
//  Created by Miguel A Hidalgo on 10/17/17.
//

#ifndef fireworkParticles_hpp
#define fireworkParticles_hpp

#include "ofMain.h"


class fireworkParticles
{
public:
    
    void setupMe() {
        //--- LAUNCHER ---//
        //Position & Velocity
        posL.x = ofRandom(200,1000);
        posL.y = ofGetWindowHeight()-radL;
        velL.x = 0;
        velL.y = ofRandom(-2,-5);
        //Color
        colL.r = 249;
        colL.g = 205;
        colL.b = 247;
        // Radius
        radL = 3;
        
        
        //--- EXPLOSION ---//
        
        for(int i=0; i<500; i++) {
            //Position & Velocity
            posE[i].x = posL.x;
            posE[i].y = ofGetWindowHeight()/2;
            velE[i].x = ofRandom(-2, 2);
            velE[i].y = ofRandom(-2, 2);
            
            accE[i].y = ofRandom(-0.08, 0);
            
            //Radius
            radE[i] = ofRandom(2,2.3);
            }
        //Color
        colE.r = 249;
        colE.g = ofRandom(150, 204);
        colE.b = ofRandom(150, 247);
        
        timeCount = 0;
        
        
    }
    
    void updateMe() {
        //--- LAUNCHER ---//
        //Speed
        posL.x += ofRandom(-2, 2);
        posL.y += velL.y;
        
        timeCount += 0.1;
        
        //--- EXPLOSION ---//
        //Explosion IF
        if(posL.y <= ofGetWindowHeight()/2) {
            colL.a = 0;
            for(int i=0; i<500; i++){
                
                if(timeCount >= 17){
                    velE[i] -= accE[i];
                }
            
                posE[i] += velE[i];
                
            }
        }
        //Color
        colE.a -= 0.08;
        
    
    }
    
    void drawMe() {
        //--- LAUNCHER ---//
        ofSetColor(colL);
        ofDrawCircle(posL, radL);
        
        //--- EXPLOSION ---//
        if (posL.y <= ofGetWindowHeight()/2){
            for(int i=0; i < 500;  i++) {
                ofSetColor(colE);
                ofDrawCircle(posE[i], radE[i]);
            }
        }
        
       
    }
    //Launch = L
    ofPoint posL;
    ofPoint velL;
    ofColor colL;
    //Explosion = E
    ofPoint posE[500];
    ofPoint velE[500];
    ofColor colE;
    ofPoint accE[500];
    
    float timeCount;
    float radE[500];
    int radL;
    
};

#endif /* fireworkParticles_hpp */
