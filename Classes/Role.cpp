#include "Role.h"

USING_NS_CC;

Role::Role()
{
}


Role::~Role()
{
}


bool Role::init(){
	
	auto sfc = SpriteFrameCache::getInstance();
	if (!sfc->getSpriteFrameByName("role1_00.png")){
		sfc->addSpriteFramesWithFile("role.plist");
	}

	if (!Sprite::initWithSpriteFrameName("role1_00.png")){
		return false;
	}

	Vector<SpriteFrame*> sfs;
	for (int i = 0; i < 6; i++)
	{
		sfs.pushBack(sfc->getSpriteFrameByName(StringUtils::format("role1_0%d.png",i)));
	}
	setPhysicsBody(PhysicsBody::createBox(this->getContentSize()));
	//设置不允许选旋转
	getPhysicsBody()->setRotationEnable(false);
	getPhysicsBody()->setContactTestBitmask(1);

	auto animation = Animation::createWithSpriteFrames(sfs,0.1f);
	auto animate = Animate::create(animation);

	runAction(RepeatForever::create(animate));
	scheduleUpdate();

	return true;
}

void Role::update(float dt){
	if (this->getPosition().y<=startPoint.y+5){
		isJump = false;
	}
	else{
		isJump = true;
	}
}

void Role::jump(){
	if (!isJump){
		getPhysicsBody()->setVelocity(Vec2(0, 300));
		isJump = true;
	}
}


void Role::setStartPoint(Vec2 v){
	startPoint = v;
}