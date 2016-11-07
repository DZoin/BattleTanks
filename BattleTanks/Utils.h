#pragma once
#include<SDL_scancode.h>
#include "Action.h"
#include <iterator>
#include <list>
#include <utility>

namespace utils
{
	std::_List_iterator<std::_List_val<std::_List_simple_types<std::pair<SDL_Scancode, Action *>>>> find(
		std::_List_iterator<std::_List_val<std::_List_simple_types<std::pair<SDL_Scancode, Action *>>>> begin,
		std::_List_iterator<std::_List_val<std::_List_simple_types<std::pair<SDL_Scancode, Action *>>>> end, SDL_Scancode &val)
	{
		while (begin != end)
		{
			if (begin->first == val) return begin;
			++begin;
		}
		return end;
	}
}