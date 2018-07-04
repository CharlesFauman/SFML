#include <SFML/Graphics.hpp>
#include "gui.h"

using namespace std;
using namespace sf;


int main() {
	Model::switchFrame(Model::FrameName::game_frame);
	Model::gui->run();
}