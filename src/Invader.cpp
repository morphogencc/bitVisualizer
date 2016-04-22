#include "ofMain.h"
#include "Invader.h"

Invader::Invader(unsigned long id, int numPixels, int width, ofxVectorGraphics* vg) {
	mId = id;
	mVG = vg;
	mNumPixels = numPixels;
	mNumBits = numPixels*std::floor(mNumPixels / 2.0);
	if (mNumPixels % 2 == 1) {
		mNumBits += mNumPixels;
	}
	mWidth = width;
}

Invader::~Invader() {

}

void Invader::draw() {
	for (int pixelIndex = 0; pixelIndex < mNumBits; pixelIndex++) {
		int currentPixelValue = (mId >> pixelIndex) & 1;
		if (currentPixelValue) {
			mVG->setColor(0xFFFFFF);
			drawPixel(pixelIndex);
		}
		else {
			mVG->setColor(0x000000);
			drawPixel(pixelIndex);
		}
	}
}

void Invader::drawPixel(int pixelNumber) {
	int blockSize = mWidth / (mNumPixels + 2);
	int x = (pixelNumber / mNumPixels);
	int y = (pixelNumber % mNumPixels) + 1;
	if (x < std::floor(mNumPixels / 2.0)) {
		mVG->rect((x + 1)*blockSize + 0.05*blockSize, y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		mVG->rect((mNumPixels-x)*blockSize + 0.05*blockSize, y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
	else {
		mVG->rect((x+1)*blockSize + 0.05*blockSize, y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
}