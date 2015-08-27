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
    kinect.update();
    if( kinect.isFrameNew() ){
        ofFloatPixels depth = kinect.getRawDepthPixels();
//        ofPixels rgb = kinect.getRgbPixels();
        
        int w_depth = depth.getWidth();
        int h_depth = depth.getHeight();
//        float w_rate = rgb.getWidth() / w_depth;
//        float h_rate = rgb.getHeight() / h_depth;
        //cout <<w_rate << "," <<h_rate << endl;
        float *d = depth.getPixels();
        int d_cnt = 0;
        
        vbomesh.setMode(OF_PRIMITIVE_POINTS);
        vbomesh.clear();
        for(int y = 0; y < h_depth; y++) {
            for(int x = 0; x < w_depth; x++) {
                if (d[d_cnt] > 500 && d[d_cnt] < 6000) {
                    vbomesh.addVertex(ofVec3f(x - w_depth / 2, y, d[d_cnt] / 5));
 //                   vbomesh.addColor(rgb.getColor(x * w_rate * 1.4, y * h_rate* 1.2));
                }
                d_cnt++;
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw() {
    ofBackground(0, 0, 0);
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
