#pragma once

#include "ofxVectorGraphics.h"

class Invader {
public:
	Invader(unsigned long id, int numPixels, int width, ofxVectorGraphics* vg);
	~Invader();
	void draw();
protected:
	void drawPixel(int pixelNumber);
	unsigned long mId;
	ofxVectorGraphics* mVG;
	int mNumPixels;
	int mWidth;
	int mNumBits;
};