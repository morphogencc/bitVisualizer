#include "Quadtree.h"

Quadtree::Quadtree(int depth, std::shared_ptr<ofRectangle> boundingRect, int max_depth, int max_children) {
	mCurrentDepth = depth;
	mMaxDepth = max_depth;
	mMaxNumberOfChildren = max_children;
	mHasChildren = false;
	mBoundingRect = boundingRect;
}

Quadtree::~Quadtree() {

}

void Quadtree::insert(std::shared_ptr<ofRectangle> rect) {
	std::shared_ptr<Quadtree> subtree = getSubtree(rect);
	if (subtree != nullptr) {
		subtree->insert(rect);
	}
	else {
		mChildren.push_back(rect);
	}

	if (mChildren.size() > mMaxNumberOfChildren && mCurrentDepth < mMaxDepth && mSubtrees.empty()) {
		split();
	}
}

void Quadtree::remove(std::shared_ptr<ofRectangle> rect) {
	std::shared_ptr<Quadtree> subtree = getSubtree(rect);
	if (subtree != nullptr) {
		subtree->remove(rect);
	}
	else {
		// erase-remove idiom
		mChildren.erase(std::remove(mChildren.begin(), mChildren.end(), rect), mChildren.end());
	}
}

std::vector<std::shared_ptr<ofRectangle>> Quadtree::getNeighbors(std::shared_ptr<ofRectangle> rect) {
	if (mCurrentDepth = mMaxDepth) {
		return mChildren;
	}

	std::vector<std::shared_ptr<ofRectangle> > neighbors;

	if (neighbors.empty()) {
		neighbors.insert(neighbors.end(), mChildren.begin(), mChildren.end());
	}

	std::shared_ptr<Quadtree> subtree = getSubtree(rect);

	if (subtree != nullptr) {
		std::vector<std::shared_ptr<ofRectangle> > children = subtree->getNeighbors(rect);
		neighbors.insert(neighbors.end(), children.begin(), children.end());
		return neighbors;
	}

	return neighbors;
}

void Quadtree::clear() {
	mChildren.clear();
	for (auto subtree : mSubtrees) {
		subtree->clear();
	}
}

std::vector<std::shared_ptr<ofRectangle>> Quadtree::getChildren() {
	return mChildren;
}

std::vector<std::shared_ptr<ofRectangle>> Quadtree::getAllChildren() {
	std::vector<std::shared_ptr<ofRectangle> > all_children;

	all_children.insert(all_children.end(), mChildren.begin(), mChildren.end());

	for (auto subtree : mSubtrees) {
		std::vector<std::shared_ptr<ofRectangle> > c = subtree->getAllChildren();
		all_children.insert(all_children.end(), c.begin(), c.end());
	}

	return all_children;
}

void Quadtree::draw() {
	ofDrawRectangle(*mBoundingRect);
	for (auto tree : mSubtrees) {
		tree->draw();
	}
}

void Quadtree::setMaxChildren(int children) {
	mMaxNumberOfChildren = children;
}

int Quadtree::getMaxChildren() {
	return mMaxNumberOfChildren;
}

void Quadtree::setMaxDepth(int depth) {
	mMaxDepth = depth;
}

int Quadtree::getMaxDepth() {
	return mMaxDepth;
}

std::shared_ptr<Quadtree> Quadtree::getSubtree(std::shared_ptr<ofRectangle> rect) {
	if (mSubtrees.empty()) {
		return nullptr;
	}

	else {
		ofPoint center = mBoundingRect->getCenter();
		if (rect->getMinY() < center.y && rect->getMaxY() < center.y) {
			// in the top half
			if (rect->getMinX() > center.x && rect->getMaxX() > center.x) {
				// in the top-right quadrant
				return mSubtrees[1];
			}
			else if (rect->getMinX() < center.x && rect->getMaxX() < center.x) {
				// in the top-left quadrant
				return mSubtrees[0];
			}
		}
		else if (rect->getMinY() > center.y && rect->getMaxY() > center.y) {
			if (rect->getMinX() > center.x && rect->getMaxX() > center.x) {
				// in the bottom-right quadrant
				return mSubtrees[3];
			}
			else if (rect->getMinX() < center.x && rect->getMaxX() < center.x) {
				// in the bottom-left quadrant
				return mSubtrees[2];
			}
		}
	}

	return nullptr;
}

void Quadtree::split() {
	float new_width = mBoundingRect->getWidth() / 2.0;
	float new_height = mBoundingRect->getHeight() / 2.0;
	mSubtrees.push_back(std::make_shared<Quadtree>(mCurrentDepth + 1, std::make_shared<ofRectangle>(mBoundingRect->getMinX(), mBoundingRect->getMinY(), new_width, new_height), mMaxDepth, mMaxNumberOfChildren));
	mSubtrees.push_back(std::make_shared<Quadtree>(mCurrentDepth + 1, std::make_shared<ofRectangle>(mBoundingRect->getCenter().x, mBoundingRect->getMinY(), new_width, new_height), mMaxDepth, mMaxNumberOfChildren));
	mSubtrees.push_back(std::make_shared<Quadtree>(mCurrentDepth + 1, std::make_shared<ofRectangle>(mBoundingRect->getMinX(), mBoundingRect->getCenter().y, new_width, new_height), mMaxDepth, mMaxNumberOfChildren));
	mSubtrees.push_back(std::make_shared<Quadtree>(mCurrentDepth + 1, std::make_shared<ofRectangle>(mBoundingRect->getCenter().x, mBoundingRect->getCenter().y, new_width, new_height), mMaxDepth, mMaxNumberOfChildren));

	// save children, clear the tree, and re-insert them
	std::vector<std::shared_ptr<ofRectangle> > temp_children = getChildren();
	clear();
	for (auto child : temp_children) {
		insert(child);
	}
}