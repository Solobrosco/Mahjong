#ifndef BOARDGAME_H
#define BOARDGAME_H

#include <server.h>

enum MouseButton {left, right, unknown};

class BoardGame {
public:
	virtual void reset() = 0;

	virtual void handle(int, int, MouseButton=left) = 0;

	virtual ucm::json getBoard() = 0;

	virtual ~BoardGame() {}
};

#endif
