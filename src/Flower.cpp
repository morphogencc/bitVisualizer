#include "ofMain.h"
#include "Flower.h"

Flower::Flower(unsigned long id, int numPixels, ofxVectorGraphics* vg) {
	mNumBits = std::ceil(mPixelDimension / 2.0) * std::ceil(mPixelDimension / 2.0);
}

Flower::~Flower() {
}

void Flower::drawPixel(int px, int py, int width, int pixelNumber) {
	int blockSize = width / (mPixelDimension + 2);
	int x = (pixelNumber / std::ceil(mPixelDimension / 2.0));
	int y = (pixelNumber % (int)std::ceil(mPixelDimension / 2.0));

	if (x < std::ceil(mPixelDimension / 2.0) && y < std::ceil(mPixelDimension / 2.0)) {
		// enforce bilateral symmetry by having one bit equal two pixels for certain ones.  std::floor makes this work for odd dimensionalities.
		ofDrawRectangle(px + (x + 1)*blockSize + 0.05*blockSize, py + (y+1)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		ofDrawRectangle(px + (mPixelDimension - y)*blockSize + 0.05*blockSize, py + (x + 1)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		ofDrawRectangle(px + (mPixelDimension - x)*blockSize + 0.05*blockSize, py + (mPixelDimension - y)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		ofDrawRectangle(px + (y + 1)*blockSize + 0.05*blockSize, py + (mPixelDimension - x)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
	else if (x == std::ceil(mPixelDimension / 2.0) ^ y == std::ceil(mPixelDimension / 2.0)) {
		ofDrawRectangle(px + (x + 1)*blockSize + 0.05*blockSize, py + (y + 1)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		ofDrawRectangle(px + (mPixelDimension - x)*blockSize + 0.05*blockSize, py + (mPixelDimension - y)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
	else {
		ofDrawRectangle(px + (x + 1)*blockSize + 0.05*blockSize, py + (y + 1)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
}