#pragma once

#include "ofxVectorGraphics.h"
#include "BitVisualizer.h"

class Invader : public BitVisualizer {
public:
	Invader(unsigned long id, int numPixels, ofxVectorGraphics* vg);
	~Invader();
protected:
	void drawPixel(int px, int py, int width, int pixelNumber);
	int mNumBits;
};