#pragma once
#ifndef MODEL_H
#define MODEL_H
#include <unordered_map>

#include "gui.h"
#include "frame.h"

class GUI;
class GameFrame;
class Model{
public:
	static Frame* active_frame;
	static GUI* gui;

	enum FrameName { game_frame, game_over_frame, you_win_frame};

	static void const switchFrame(FrameName frame_name);

private:
	Model() {}
	static std::unordered_map<FrameName, Frame*> frame_map;

	static std::unordered_map<FrameName, Frame*>  init_map();
};

#endif