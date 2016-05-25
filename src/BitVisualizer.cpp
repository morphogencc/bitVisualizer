#include "BitVisualizer.h"

BitVisualizer::BitVisualizer(unsigned long id, int pixelDimension, ofxVectorGraphics* graphicsInstance) {
	mId = id;
	mVectorInstance = graphicsInstance;
	mPixelDimension = pixelDimension;
	mNumBits = -1;
}

BitVisualizer::~BitVisualizer() {

}

void BitVisualizer::draw(int px, int py, int width) {
	if (mNumBits == -1) {
		std::printf("BitVisualizer::draw() -- Please set the number of bits in your constructor!  Cannot draw without the number of bits to use.\n");
	}
	// general idea -- convert each id number to a string of bits.  If the bit is 1, create a white pixel.  If the bit is 0, create a black pixel.
	for (int pixelIndex = 0; pixelIndex < mNumBits; pixelIndex++) {
		int currentPixelValue = (mId >> pixelIndex) & 1;
		if (!currentPixelValue) {
			mVectorInstance->setColor(0xFFFFFF);
		}
		else {
			mVectorInstance->setColor(0x000000);
			drawPixel(px, py, width, pixelIndex);
		}
	}
}