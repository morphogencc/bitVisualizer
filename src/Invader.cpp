#include "ofMain.h"
#include "Invader.h"

Invader::Invader(unsigned long id, int numPixels, int width, ofxVectorGraphics* vg) {
	mId = id; // id number, to give each glyph a unique reproducible id
	mVG = vg;
	mNumPixels = numPixels; // dimensionality of glyph -- 5 means 5x5, etc 
	mNumBits = numPixels*std::floor(mNumPixels / 2.0);
	if (mNumPixels % 2 == 1) {
		mNumBits += mNumPixels;
	}
	mWidth = width;
}

Invader::~Invader() {

}

void Invader::draw(int px, int py) {
	// general idea -- convert each id number to a string of bits.  If the bit is 1, create a white pixel.  If the bit is 0, create a black pixel.
	for (int pixelIndex = 0; pixelIndex < mNumBits; pixelIndex++) {
		int currentPixelValue = (mId >> pixelIndex) & 1;
		if (!currentPixelValue) {
			mVG->setColor(0xFFFFFF);
			//drawPixel(pixelIndex);
		}
		else {
			mVG->setColor(0x000000);
			drawPixel(px, py, pixelIndex);
		}
	}
}

void Invader::drawPixel(int px, int py, int pixelNumber) {
	int blockSize = mWidth / (mNumPixels + 2);
	int x = (pixelNumber / mNumPixels);
	int y = (pixelNumber % mNumPixels) + 1;
	if (x < std::floor(mNumPixels / 2.0)) {
		// enforce bilateral symmetry by having one bit equal two pixels for certain ones.  std::floor makes this work for odd dimensionalities.
		mVG->rect(px + (x + 1)*blockSize + 0.05*blockSize, py + y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		mVG->rect(px + (mNumPixels-x)*blockSize + 0.05*blockSize, py + y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
	else {
		mVG->rect(px + (x + 1)*blockSize + 0.05*blockSize, py + y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
}