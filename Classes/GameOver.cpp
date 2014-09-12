#include "GameOver.h"

USING_NS_CC;

GameOver::GameOver()
{
}


GameOver::~GameOver()
{
}

bool GameOver::init(){
	if (!LayerColor::initWithColor(Color4B(255,255,255,255))){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto go = Label::createWithTTF("Game Over", "fonts/Marker Felt.ttf", 40);
	go->setPosition(Vec2(visibleSize.width / 2, visibleSize.height -go->getContentSize().height*3));
	go->setColor(Color3B::BLACK);
	this->addChild(go);

	auto restart = Label::createWithTTF("Restart", "fonts/Marker Felt.ttf", 35);
	restart->setColor(Color3B::BLACK);

	auto home = Label::createWithTTF("Home", "fonts/Marker Felt.ttf", 35);
	home->setColor(Color3B::BLACK);

	auto restartItem = MenuItemLabel::create(restart, [](Ref *r){
		Director::getInstance()->replaceScene(HelloWorld::createScene());
	});
	auto homeItem = MenuItemLabel::create(home, [](Ref *r){
		Director::getInstance()->replaceScene(Home::createScene());
	});

	auto m = Menu::create(restartItem, homeItem, NULL);
	m->alignItemsVerticallyWithPadding(10);
	addChild(m);

	return true;
}


Scene* GameOver::createScene(){
	auto s = Scene::create();
	auto go = GameOver::create();
	s->addChild(go);
	return s;
}