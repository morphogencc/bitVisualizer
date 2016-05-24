#pragma once

#include "ofxVectorGraphics.h"

class Flower {
public:
	Flower(unsigned long id, int numPixels, int width, ofxVectorGraphics* vg);
	~Flower();
	void draw(int px, int py);
protected:
	void drawPixel(int px, int py, int pixelNumber);
	unsigned long mId;
	ofxVectorGraphics* mVG;
	int mNumPixels;
	int mWidth;
	int mNumBits;
};