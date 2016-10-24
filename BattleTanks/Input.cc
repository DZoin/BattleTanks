#include "Input.h"

/* Input class
 * Keeps track of keyboard state
 */

/* This function gets called at the beginning of each frame
 * to reset keys that are no longer relevent
*/
void Input::beginNewFrame()
{
	_pressedKeys.clear();
	_releasedKeys.clear();
}
void Input::keyDownEvent(const SDL_Event& event)
{
	_pressedKeys[event.key.keysym.scancode] = true;
	_heldKeys[event.key.keysym.scancode] = true;
}
void Input::keyUpEvent(const SDL_Event& event)
{
	_releasedKeys[event.key.keysym.scancode] = true;
	_heldKeys[event.key.keysym.scancode] = false;
}
bool Input::wasKeyPressed(SDL_Scancode key)
{
	return _pressedKeys[key];
}
bool Input::wasKeyReleased(SDL_Scancode key)
{
	return _releasedKeys[key];
}
bool Input::isKeyHeld(SDL_Scancode key)
{
	return _heldKeys[key];
}