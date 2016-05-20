#include "ofApp.h"
#include <cstdlib>

//--------------------------------------------------------------
void ofApp::setup() {
	/*
	output.beginEPS("invaders.eps", 0, 0, 5100, 3300);
	output.fill();

	uint16_t id = 0;

	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 33; j++) {
			//std::printf("Generating invader of id %d\n", id);
			mInvader = new Invader(id, 5, 100, &output);
			mInvader->draw(i*100, j*100);
			id++;
			delete mInvader;
		}
	}

	output.endEPS();

	std::printf("Saving complete!\n");
	*/
	mQuadtree = std::make_shared<Quadtree>(0, std::make_shared<ofRectangle>(0, 0, ofGetWidth(), ofGetHeight()));
	mQuadtree->insert(std::make_shared<ofRectangle>(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), 25, 25));
	mQuadtree->setMaxDepth(1);
	mQuadtree->setMaxChildren(99);

	while(mQuadtree->getAllChildren().size() < 10) {
		int size = ofRandom(10,100);
		int pos_x = ofRandom(ofGetWidth());
		int pos_y = ofRandom(ofGetHeight());

		bool removeRectangle = false;
		std::shared_ptr<ofRectangle> test_rect = std::make_shared<ofRectangle>(pos_x, pos_y, size, size);

		for (auto child : mQuadtree->getNeighbors(test_rect)) {
			bool intersects = child->intersects(*test_rect);
			if (intersects) {
				std::printf("Intersects!\n");
				removeRectangle = true;
			}
			else {
			}
		}

		if (!removeRectangle) {
			std::printf("Added a rectangle.\n");
			mQuadtree->insert(std::make_shared<ofRectangle>(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), size, size));
		}

	}

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);

	ofSetColor(255);
	ofFill();
	for (auto child : mQuadtree->getAllChildren()) {
		ofSetColor(255);
		ofFill();
		ofDrawRectangle(*child);

		ofSetColor(0);
		ofNoFill();
		ofDrawRectangle(*child);
	}

	ofSetColor(128);
	ofNoFill();
	mQuadtree->draw();
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
