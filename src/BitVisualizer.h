#pragma once

#include "ofxVectorGraphics.h"

class BitVisualizer {
public:
	BitVisualizer(unsigned long id, int pixelDimension, ofxVectorGraphics* graphicsInstance);
	~BitVisualizer();
	void draw(int px, int py, int width);
protected:
	virtual void drawPixel(int px, int py, int width, int pixelNumber) = 0;
	unsigned long mId;
	ofxVectorGraphics* mVectorInstance;
	int mPixelDimension;
	int mWidth;
	int mNumBits;
};