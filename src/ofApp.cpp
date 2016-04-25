#include "ofApp.h"
#include <cstdlib>

//--------------------------------------------------------------
void ofApp::setup(){
	//mFbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA);
	//mFbo.begin();
	ofBackground(0);

//	ofImage img;
	output.beginEPS("invaders.eps");
	output.fill();

	uint16_t id = 0;

	for (int i = 0; i < 257; i++) {
		for (int j = 0; j < 255; j++) {
			//std::printf("Generating invader of id %d\n", id);
			mInvader = new Invader(id, 5, 100, &output);
			mInvader->draw(i*100, j*100);
			id++;
			delete mInvader;
		}
	}

	output.endEPS();

	//mFbo.end();
	//mFbo.draw(0, 0);
	//img.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
	//std::ostringstream filepath;
	//filepath << ofGetFrameNum() << ".png";
//	std::string filepath = "all_invaders.png";
//	mFbo.readToPixels(mPixels);
//	ofSaveImage(mPixels, filepath, OF_IMAGE_QUALITY_BEST);
	std::printf("Saving complete!\n");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
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
