#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"
#include "renderer.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake &snake,Renderer &renderer) const;

 private:
  void ChangeDirection(Snake &snake, Snake::Direction input,
                       Snake::Direction opposite) const;
};

#endif