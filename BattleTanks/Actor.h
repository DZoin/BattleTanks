#pragma once
class Actor
{
public:
	Actor();
	virtual ~Actor() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

