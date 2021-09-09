#include <iostream>
#include <thread>
#include "controller.h"
#include "game.h"
#include "renderer.h"
#include "score.h"



int main() {
  constexpr std::size_t kFramesPerSecond{60};
  constexpr std::size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr std::size_t kScreenWidth{640};
  constexpr std::size_t kScreenHeight{640};
  constexpr std::size_t kGridWidth{40};
  constexpr std::size_t kGridHeight{40};
  PrintScore print;



  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, renderer, kMsPerFrame);

 

  print.getScore(game.GetScore());
  std::cout << "Size: " << game.GetSize() << "\n";

  return 0;


}