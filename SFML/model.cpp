#include "model.h"
#include "game_over_frame.h"
#include "you_win_frame.h"

Frame* Model::active_frame = NULL;
GUI* Model::gui = new GUI();

std::unordered_map<Model::FrameName, Frame*>  Model::init_map() {
	std::unordered_map<FrameName, Frame*>  new_map;
	new_map[game_frame] = new GameFrame();
	new_map[game_over_frame] = new GameOverFrame();
	new_map[you_win_frame] = new YouWinFrame();
	return new_map;
}

std::unordered_map<Model::FrameName, Frame*> Model::frame_map = Model::init_map();

void const Model::switchFrame(FrameName frame_name) {
	active_frame = frame_map.find(frame_name)->second;
}