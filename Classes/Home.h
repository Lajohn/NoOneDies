#ifndef _HOME_H_
#define _HOME_H_

#include "cocos2d.h"
#include "HelloWorldScene.h"


class Home:public cocos2d::LayerColor
{
public:
	Home();
	~Home();

	virtual bool init();
	CREATE_FUNC(Home);
	static cocos2d::Scene* createScene();
};


#endif // !_HOME_H_