#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    if( !ofFile::doesFileExist("11to16.bin") ){
        ofSystemAlertDialog("Make sure you have 11to16.bin, xTable.bin and zTable.bin in your data folder!");
        ofExit();
    }
    
    kinect.open();
	ofEasyCam easyCam;
}

//--------------------------------------------------------------
void ofApp::update(){
	ofBackground(0, 0, 0);
    kinect.update();
    if( kinect.isFrameNew() ){
        ofp = kinect.getRawDepthPixels();
        
        vbomesh.setMode(OF_PRIMITIVE_POINTS);
        vbomesh.clear();
        
        int w = ofp.getWidth();
        int h = ofp.getHeight();
        float *d = ofp.getPixels();
        int d_cnt = 0;
        
        for(int y = 0; y < h; y++) {
            for(int x = 0; x < w; x++) {
                vbomesh.addVertex(ofVec3f(x-w/2, y, d[d_cnt++] / 5));
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofSetColor(255, 255, 255);
    easyCam.begin();
    ofPushMatrix();
    ofScale(1, -1, -1);
    vbomesh.drawFaces();
    ofPopMatrix();
    easyCam.end();
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
