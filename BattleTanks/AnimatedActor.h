#ifndef ANIMATED_SPRITE_H
#define ANIMATED_SPRITE_H
#include "Actor.h"
#include "Globals.h"
#include <string>
#include <map>
#include <vector>
using namespace std;

class Canvas;
class Actor;

// Holds logic for animating sprites

class AnimatedActor : public Actor
{
public:
	AnimatedActor();
	AnimatedActor(Canvas &canvas, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate); //timeToUpdate -> How long until you are supposed to go to the next frame in your animation

	// Plays the animation provided if it's not already playing
	void playAnimation(std::string animation, bool once = false);

	// Updates the animated sprite(timer)
	void update(int elapsedTime);

	// Draws the sprite to the screen
	void draw(Canvas &canvas, int x, int y);

protected:
	double _timeToUpdate;  //Amount of time between frames
	bool _currentAnimationOnce; // Wheter or not an animation is only being played once
	std::string _currentAnimation;  // The name of the current animation that is being played right now

	// How we add animations to our list of animations
	// int frames -> the number of frames in the animation
	void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offsets);

	// Resets all animations assosiated with this sprite
	void resetAnimations();

	// Stops the current animation
	void stopAnimation();

	// Changes the visibility of the animated sprite
	void setVisible(bool visible);

	// Logic that happens when an animation ends
	virtual void animationDone(std::string currentAnimation) = 0;

	// A required function that sets up all animations for a sprite
	virtual void setUpAnimations() = 0;

private:

	std::map<std::string, std::vector<SDL_Rect>> _animations;  //Map full of animations, keeps track of all the animations we have
	std::map<std::string, Vector2> _offsets;  //If there are any offsets in the sprite sheet we use, we need to set them

	int _frameIndex; // Which frame in the animation we are at
	double _timeElapsed = 0.0;  // Our timer
	bool _visible;  // Wheter or not the animation is visible
};

#endif