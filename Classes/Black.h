#ifndef _BLACK_H_
#define _BLACK_H_

#include "cocos2d.h"

class Black :public cocos2d::Sprite
{
public:
	Black();
	~Black();

	virtual bool init();
	CREATE_FUNC(Black);
	virtual void update(float dt);

};


#endif // !_BLACK_H_