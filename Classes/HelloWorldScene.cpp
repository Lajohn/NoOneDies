#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setGravity(Vec2(0,-600));
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
	if (!LayerColor::initWithColor(Color4B(255, 255, 255, 255)))
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


	auto h = visibleSize.height / 3;
	for (int i = 0; i < 3; i++)
	{
		gcs.insert(0, GameController::create(this, i*h+30));
	}

	scheduleUpdate();

	auto listener = EventListenerPhysicsContact::create();
	listener->onContactBegin = [this](PhysicsContact &contact){
		this->unscheduleUpdate();
		Director::getInstance()->replaceScene(GameOver::createScene());
		return true;
	};

	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = [&](Touch *t,Event *e){
		for (auto it = gcs.begin(); it != gcs.end();it++){
			if ((*it)->hisTestPoint(t->getLocation())){

				(*it)->roleJump();
				break;
			}
		}
		return false;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    return true;
}


void HelloWorld::update(float dt){
	for (auto it = gcs.begin(); it != gcs.end(); it++)
	{
		(*it)->addBlack();
	}
}




void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
