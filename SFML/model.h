#pragma once
#include <unordered_map>

#include "gui.h"
#include "frame.h"

class GUI;
class Model{
public:
	static Frame* active_frame;
	static GUI* gui;

	enum FrameName { game_frame };

	void const switchFrame(FrameName frame_name);

private:
	Model() {}
	static std::unordered_map<FrameName, Frame> frame_map;
};