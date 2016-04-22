#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
	ofSetFrameRate(2.0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofImage img;
	output.beginEPS("invaders.eps");

	ofBackground(255);
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 10; j++) {
			ofPushMatrix();
			ofTranslate(i * 100, j * 100, 0);
			mInvader = new Invader(std::rand(), 5, 100, &output);
			mInvader->draw();
			ofPopMatrix();
		}
	}

	img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	std::ostringstream filepath;
	filepath << ofGetFrameNum() << ".png";
	output.endEPS();

	//ofSaveImage(img.getPixels(), filepath.str(), OF_IMAGE_QUALITY_BEST);
	//exit();
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
