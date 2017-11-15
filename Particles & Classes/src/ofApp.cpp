#include "ofApp.h"

#include "snowParticles.hpp"
#include "fireworkParticles.hpp"


float timeCount;

snowParticles snowP[1000];
fireworkParticles fireworkP[2];
bool launch;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(17, 28, 41);
    ofSetWindowShape(1200, 800);
    
    launch = false;
    
    for(int i=0; i<2; i++) {
        fireworkP[i].setupMe();
    }
   
    timeCount = 0;
    
    //SnowBalls
    for(int i=0; i<1000; i++) {
        snowP[i].setupMe();
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if(launch == true){
        for(int i=0; i<2; i++) {
            fireworkP[i].updateMe();
            
        }
//        launch = false;
    }
    
    
    for(int i=0; i<1000; i++) {
        snowP[i].updateMe();
    }
    
//    timeCount += 0.1;
//
//    if(timeCount >= 40){
//        timeCount = 0;
//    }
//
//    cout << timeCount << endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(launch == true){
        for(int i=0; i<2; i++) {
            fireworkP[i].drawMe();
        }
    }
        
    
    for(int i=0; i<1000;  i++) {
        snowP[i].drawMe();
    }

    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    launch = true;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
