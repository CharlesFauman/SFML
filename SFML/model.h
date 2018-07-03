#pragma once
#include <unordered_map>

#include "frame.h"

class Model{
public:
	static Frame* active_frame;

	//enum FrameName { game_frame };

private:
	Model() {}

	//unordered_map<FrameName, Frame> frame_map;
};