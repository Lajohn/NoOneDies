#include "Edge.h"

USING_NS_CC;

Edge::Edge()
{
}


Edge::~Edge()
{
}


bool Edge::init(){
	if (!Node::init()){
		return false;
	} 

	Size visibleSize=Director::getInstance()->getVisibleSize();

	setPhysicsBody(PhysicsBody::createEdgeBox(visibleSize));
	setContentSize(visibleSize);




	return true;
}