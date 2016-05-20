#pragma once

#include "ofMain.h"
#include <memory>

class Quadtree {
public:
	Quadtree(int depth, std::shared_ptr<ofRectangle> boundingRect, int max_depth = 10, int max_children = 4);
	~Quadtree();
	void insert(std::shared_ptr<ofRectangle> rect);
	void remove(std::shared_ptr<ofRectangle> rect);
	std::vector<std::shared_ptr<ofRectangle>> getNeighbors(std::shared_ptr<ofRectangle> rect);
	void clear();
	std::vector<std::shared_ptr<ofRectangle>> getChildren();
	std::vector<std::shared_ptr<ofRectangle>> getAllChildren();
	void draw();
	void setMaxChildren(int children);
	int getMaxChildren();
	void setMaxDepth(int depth);
	int getMaxDepth();
protected:
	std::shared_ptr<Quadtree> getSubtree(std::shared_ptr<ofRectangle> rect);
	void split();
	std::vector<std::shared_ptr<ofRectangle>> mChildren;
	std::vector<std::shared_ptr<Quadtree> > mSubtrees;
	bool mHasChildren;
	int mMaxNumberOfChildren;
	int mCurrentDepth;
	int mMaxDepth;
	std::shared_ptr<ofRectangle> mBoundingRect;
};