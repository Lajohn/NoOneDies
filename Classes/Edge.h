#ifndef _EDGE_H_
#define	_EDGE_H_

#include "cocos2d.h"

class Edge:public cocos2d::Node
{
public:
	Edge();
	~Edge();

	virtual bool init();
	CREATE_FUNC(Edge);
};


#endif // !_EDGE_H_