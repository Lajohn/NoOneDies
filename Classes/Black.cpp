#include "Black.h"

USING_NS_CC;

Black::Black()
{
}


Black::~Black()
{
}


bool Black::init(){
	if (!Sprite::init()){
		return false;
	}

	Size size = Size(rand()%20+5,rand()%30+10);
	Size visibleSize = Director::getInstance()->getVisibleSize();

	setPhysicsBody(PhysicsBody::createBox(size));
	setTextureRect(Rect(0, 0, size.width, size.height));
	setColor(Color3B(0, 0, 0));
	setContentSize(size);

	setPositionX(visibleSize.width);
	//���ü�ʱ��
	scheduleUpdate();

	//�����Ƿ�Ϊ��̬����
	getPhysicsBody()->setDynamic(false);
	getPhysicsBody()->setContactTestBitmask(1);
	return true;
}


void Black::update(float dt){
	setPositionX(getPositionX()-2);
	if (getPositionX()<0){
		log(">>>>>>>>>>>>>>>>>>>>>>>");
		removeFromParent();
	}
}