#pragma once

#include "ofxVectorGraphics.h"
#include "BitVisualizer.h"

class Flower : public BitVisualizer {
public:
	Flower(unsigned long id, int numPixels, ofxVectorGraphics* vg);
	~Flower();
protected:
	void drawPixel(int px, int py, int width, int pixelNumber);
	int mNumBits;
};