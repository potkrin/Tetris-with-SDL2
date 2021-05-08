/*****************************************************************************************
/* File: IO.cpp
/* Desc: Class for handling inpung & drawing, it uses SDL for the rendering. Change the methods
/* of this class in order to use a different renderer
/*
/*
/* gametuto.com - Javier López López (javilop.com)
/*
/*****************************************************************************************
/*
/* Creative Commons - Attribution 3.0 Unported
/* You are free:
/*	to Share — to copy, distribute and transmit the work
/*	to Remix — to adapt the work
/*
/* Under the following conditions:
/* Attribution. You must attribute the work in the manner specified by the author or licensor
/* (but not in any way that suggests that they endorse you or your use of the work).
/*
/*****************************************************************************************/

// ------ Includes -----

#include "IO.h"
#include <stdio.h>

static SDL_Window* window;
static SDL_Surface* mScreen;										// Screen
static Uint32 mColors[COLOR_MAX] = { 0x000000ff,					// Colors
							   0xff0000ff, 0x00ff00ff, 0x0000ffff,
							   0x00ffffff, 0xff00ffff, 0xffff00ff,
							   0xffffffff };

/*
======================================
Init
======================================
*/
IO::IO()
{
	InitGraph();
}

void IO::boxColor(SDL_Surface* screen, int x1, int y1, int x2, int y2, Uint32 color)
{
	SDL_Rect rect{ x1, y1, x2 - x1, y2 - y1 };
	SDL_FillRect(screen, &rect, color);
}

/*
======================================
Clear the screen to black
======================================
*/
void IO::ClearScreen()
{
	boxColor(mScreen, 0, 0, mScreen->w - 1, mScreen->h - 1, mColors[BLACK]);
}


/*
======================================
Draw a rectangle of a given color

Parameters:
>> pX1, pY1: 		Upper left corner of the rectangle
>> pX2, pY2: 		Lower right corner of the rectangle
>> pC				Rectangle color
======================================
*/
void IO::DrawRectangle(int pX1, int pY1, int pX2, int pY2, enum color pC)
{
	boxColor(mScreen, pX1, pY1, pX2, pY2 - 1, mColors[pC]);
}


/*
======================================
Return the screen height
======================================
*/
int IO::GetScreenHeight()
{
	return mScreen->h;
}


/*
======================================
Update screen
======================================
*/
void IO::UpdateScreen()
{
	//sdl ver1.x
	//SDL_Flip(mScreen);

	//sdl ver2.x
	SDL_UpdateWindowSurface(window);
}


/*
======================================
Keyboard Input
======================================
*/
int IO::Pollkey()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) {
		case SDL_KEYDOWN:
			return event.key.keysym.sym;
		case SDL_QUIT:
			exit(3);
		}
	}
	return -1;
}

/*
======================================
Keyboard Input
======================================
*/
int IO::Getkey()
{
	SDL_Event event;
	while (true)
	{
		SDL_WaitEvent(&event);
		if (event.type == SDL_KEYDOWN)
			break;
		if (event.type == SDL_QUIT)
			exit(3);
	};
	return event.key.keysym.sym;
}

/*
======================================
Keyboard Input
======================================
*/
int IO::IsKeyDown(int pKey)
{
	const Uint8* mKeytable;
	int mNumkeys;
	SDL_PumpEvents();
	mKeytable = SDL_GetKeyboardState(&mNumkeys);
	return mKeytable[pKey];
}

/*
======================================
SDL Graphical Initialization
======================================
*/
int IO::InitGraph()
{
	/*
	const SDL_VideoInfo* info;
	Uint8  video_bpp;
	Uint32 videoflags;

	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
		return 1;
	}
	atexit(SDL_Quit);

	// Alpha blending doesn't work well at 8-bit color
	info = SDL_GetVideoInfo();
	if (info->vfmt->BitsPerPixel > 8) {
		video_bpp = info->vfmt->BitsPerPixel;
	}
	else {
		video_bpp = 16;
	}
	videoflags = SDL_SWSURFACE | SDL_DOUBLEBUF;

	// Set 640x480 video mode
	if ((mScreen = SDL_SetVideoMode(640, 480, video_bpp, videoflags)) == NULL) {
		fprintf(stderr, "Couldn't set %ix%i video mode: %s\n", 640, 480, SDL_GetError());
		return 2;
	}
	return 0;
	*/

	//SDL ver2.x

	//The window we'll be rendering to
	window = NULL;

	//The surface contained by the window
	mScreen = NULL;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else
		{
			//Get window surface
			mScreen = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(mScreen, NULL, SDL_MapRGB(mScreen->format, 0xFF, 0xFF, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}
	return 0;
}


