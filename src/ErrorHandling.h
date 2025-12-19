/*
 * ErrorHandling.h
 *
 *  Created on: 18.12.2025
 *      Author: mike
 */

#pragma once
#include <SDL3/SDL.h>
#include <iostream>
#include <string>


#define ERROR_LOGGING

void CheckSDLError(const std::string& Action) {
#ifdef ERROR_LOGGING
	const char* Error{SDL_GetError()};
	if (*Error != '\0') {
		std::cout << Action << " Error: " << Error << std::endl;
		SDL_ClearError();
	}
#endif
}
