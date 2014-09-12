#ifndef _GAME_CONTROLLER_H_
#define _GAME_CONTROLLER_H_

#include "cocos2d.h"
#include "Edge.h"
#include "Role.h"
#include "Black.h"


class GameController:public cocos2d::Ref
{

private:
	cocos2d::Layer *_layer;
	float _positionY;
	cocos2d::Size visibleSize;
	int currentFrameIndex;
	int nextFrameCount;
	Edge *edge;
	Role *role;
public:
	GameController();
	~GameController();

	virtual bool init(cocos2d::Layer *layer, float positionY);
	static GameController* create(cocos2d::Layer *layer, float positionY);
	void addBlack();
	void resetFrames();
	bool hisTestPoint(cocos2d::Vec2 v);
	void roleJump();
};


#endif // !_GAME_CONTROLLER_H_