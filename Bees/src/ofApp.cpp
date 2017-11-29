#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    

    
    ofSetWindowTitle("Bees");
    ofSetWindowShape(1920, 1080);
    ofSetFrameRate(60);
    ofBackground(255, 255, 255);
    ofEnableSmoothing();
    
    dipperImage.load("dipper.png");
    beeImage.load("bee.png");
    bgImage.load("bg.png");
    
    
    
    
    for(int i=0; i<100; i++)
    {
        Bee f;
        f.setup(beeImage);
        myBees.push_back(f);
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    CGDisplayHideCursor(kCGDirectMainDisplay);
    
    for(int i=0; i<myBees.size(); i++)
    {
        myBees[i].update(mouse, myBees);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    bgImage.draw(0,0, 1920, 1080);
    dipperImage.draw(mouse.x-60, mouse.y-60, 300, 204);
    for(int i=0; i<myBees.size(); i++)
    {
        myBees[i].draw();
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
    mouse.set(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
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
