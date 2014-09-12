#include "GameController.h"

USING_NS_CC;


GameController::GameController()
{
}


GameController::~GameController()
{
}


GameController* GameController::create(Layer *layer,float positionY){

	auto gc = new GameController();
	gc->init(layer,positionY);
	gc->autorelease();
	return gc;
}

bool GameController::init(Layer *layer, float positionY){
	_layer = layer;
	_positionY = positionY;

	visibleSize = Director::getInstance()->getVisibleSize();

	edge = Edge::create();
	edge->setPosition(visibleSize.width / 2, visibleSize.height / 2+_positionY);
	layer->addChild(edge);

	auto ground = Sprite::create();
	ground->setColor(Color3B(0, 0, 0));
	ground->setTextureRect(Rect(0,0,visibleSize.width,3));
	ground->setPosition(ground->getContentSize().width/2,1.5+_positionY);
	layer->addChild(ground);

	role = Role::create();
	role->setPosition(role->getContentSize().width*2, role->getContentSize().height / 2+_positionY);
	role->setStartPoint(role->getPosition());
	layer->addChild(role);

	resetFrames();
	
	return true;
}


//Ìí¼ÓÕÏ°­
void GameController::addBlack(){
	currentFrameIndex++;
	if (currentFrameIndex>=nextFrameCount){
		resetFrames();

		auto b = Black::create();
		b->setPositionY(b->getContentSize().height/2+_positionY);
		_layer->addChild(b);
	}
}



void GameController::resetFrames(){
	currentFrameIndex = 0;
	nextFrameCount = rand() % 120 + 100;
}


bool GameController::hisTestPoint(Vec2 v){
	return edge->getBoundingBox().containsPoint(v);
}

void GameController::roleJump(){
	role->jump();
}
