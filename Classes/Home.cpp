#include "Home.h"

USING_NS_CC;

Home::Home()
{
}


Home::~Home()
{
}


bool Home::init(){
	if (!LayerColor::initWithColor(Color4B::WHITE)){
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();

	auto go = Label::createWithTTF("No One Dies", "fonts/Marker Felt.ttf", 40);
	go->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - go->getContentSize().height * 3));
	go->setColor(Color3B::BLACK);
	this->addChild(go);


	auto play = Label::createWithTTF("Play", "fonts/Marker Felt.ttf", 35);
	go->setColor(Color3B::BLACK);

	auto exit = Label::createWithTTF("Exit", "fonts/Marker Felt.ttf", 35);
	go->setColor(Color3B::BLACK);

	auto menu = Menu::create(
		MenuItemLabel::create(play, [](Ref *r){
			Director::getInstance()->replaceScene(HelloWorld::createScene());
		}),
		MenuItemLabel::create(exit, [](Ref *r){
			Director::getInstance()->end();
		}),
		NULL);

	menu->alignItemsVerticallyWithPadding(10);
	menu->setColor(Color3B::BLACK);
	this->addChild(menu);

	return true;
}


Scene* Home::createScene(){
	auto s = Scene::create();
	auto h = Home::create();
	s->addChild(h);
	return s;
}
