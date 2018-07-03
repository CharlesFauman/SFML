#include <SFML/Graphics.hpp>
#include "gui.h"

using namespace std;
using namespace sf;


int main() {
	Model::active_frame = new GameFrame();
	Model::gui->run();
}