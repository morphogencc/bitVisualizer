#include "ofMain.h"
#include "Flower.h"

Flower::Flower(unsigned long id, int numPixels, int width, ofxVectorGraphics* vg) {
	mId = id; // id number, to give each glyph a unique reproducible id
	mVG = vg;
	mNumPixels = numPixels; // dimensionality of glyph (e.g. 5 is 5x5)
	mNumBits = std::ceil(mNumPixels / 2.0) * std::ceil(mNumPixels / 2.0);

	mWidth = width;
}

Flower::~Flower() {

}

void Flower::draw(int px, int py) {
	// general idea -- convert each id number to a string of bits.  If the bit is 1, create a white pixel.  If the bit is 0, create a black pixel.
	for (int pixelIndex = 0; pixelIndex < mNumBits; pixelIndex++) {
		int currentPixelValue = (mId >> pixelIndex) & 1;
		if (!currentPixelValue) {
			ofSetColor(255);
			//drawPixel(pixelIndex);
		}
		else {
			ofSetColor(0);
			drawPixel(px, py, pixelIndex);
		}
	}
}

void Flower::drawPixel(int px, int py, int pixelNumber) {
	int blockSize = mWidth / (mNumPixels + 2);
	int x = (pixelNumber / std::ceil(mNumPixels / 2.0));
	int y = (pixelNumber % (int)std::ceil(mNumPixels / 2.0));

	std::printf("Coordinates are %d, %d out of %d\n", x, y, mNumBits);

	if (x < std::ceil(mNumPixels / 2.0) && y < std::ceil(mNumPixels / 2.0)) {
		// enforce bilateral symmetry by having one bit equal two pixels for certain ones.  std::floor makes this work for odd dimensionalities.
		ofDrawRectangle(px + (x + 1)*blockSize + 0.05*blockSize, py + (y+1)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		ofDrawRectangle(px + (mNumPixels - y)*blockSize + 0.05*blockSize, py + (x + 1)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		ofDrawRectangle(px + (mNumPixels - x)*blockSize + 0.05*blockSize, py + (mNumPixels - y)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		ofDrawRectangle(px + (y + 1)*blockSize + 0.05*blockSize, py + (mNumPixels - x)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
	else if (x == std::ceil(mNumPixels / 2.0) ^ y == std::ceil(mNumPixels / 2.0)) {
		ofDrawRectangle(px + (x + 1)*blockSize + 0.05*blockSize, py + (y + 1)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		ofDrawRectangle(px + (mNumPixels - x)*blockSize + 0.05*blockSize, py + (mNumPixels - y)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
	else {
		ofDrawRectangle(px + (x + 1)*blockSize + 0.05*blockSize, py + (y + 1)*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
}