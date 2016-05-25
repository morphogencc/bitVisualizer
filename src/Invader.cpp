#include "ofMain.h"
#include "Invader.h"

Invader::Invader(unsigned long id, int numPixels, ofxVectorGraphics* vg) : BitVisualizer(id, numPixels, vg) {
	mNumBits = numPixels*std::floor(mPixelDimension / 2.0);
	if (mPixelDimension % 2 == 1) {
		mNumBits += mPixelDimension;
	}
}

Invader::~Invader() {

}

void Invader::drawPixel(int px, int py, int width, int pixelNumber) {
	int blockSize = width / (mPixelDimension + 2);
	int x = (pixelNumber / mPixelDimension);
	int y = (pixelNumber % mPixelDimension) + 1;
	if (x < std::floor(mPixelDimension / 2.0)) {
		// enforce bilateral symmetry by having one bit equal two pixels for certain ones.  std::floor makes this work for odd dimensionalities.
		mVectorInstance->rect(px + (x + 1)*blockSize + 0.05*blockSize, py + y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
		mVectorInstance->rect(px + (mPixelDimension-x)*blockSize + 0.05*blockSize, py + y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
	else {
		mVectorInstance->rect(px + (x + 1)*blockSize + 0.05*blockSize, py + y*blockSize + 0.05*blockSize, 0.9*blockSize, 0.9*blockSize);
	}
}