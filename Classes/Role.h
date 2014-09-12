#ifndef _ROLE_H_
#define _ROLE_H_

#include "cocos2d.h"

class Role:public cocos2d::Sprite
{
private:
	bool isJump;
	cocos2d::Vec2 startPoint;
public:
	Role();
	~Role();

	virtual bool init();
	CREATE_FUNC(Role);
	virtual void update(float dt);
	void jump();
	void setStartPoint(cocos2d::Vec2 v);

};


#endif // !_ROLE_H_