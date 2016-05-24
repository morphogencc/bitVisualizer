#include "ofApp.h"
#include <cstdlib>

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(1.0);
}

//--------------------------------------------------------------
void ofApp::update(){
}

//--------------------------------------------------------------
void ofApp::draw(){
	uint16_t id = 360;

	ofBackground(255);
	ofFill();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 6; j++) {
			//std::printf("Generating invader of id %d\n", id);
			mInvader = new Flower(ofRandom(0, 65535), 8, 100, &output);
			mInvader->draw(i * 100, j * 100);
			id++;
			delete mInvader;
		}
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
