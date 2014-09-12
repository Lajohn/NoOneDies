#ifndef _GAME_OVER_H_
#define _GAME_OVER_H_

#include "cocos2d.h"
#include "HelloWorldScene.h"
#include "Home.h"

class GameOver:public cocos2d::LayerColor
{
public:
	GameOver();
	~GameOver();

	virtual bool init();
	CREATE_FUNC(GameOver);
	static cocos2d::Scene* createScene();

};


#endif // !_GAME_OVER_H_