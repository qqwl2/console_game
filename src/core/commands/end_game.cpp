#include <include/core/commands/end_game.hpp>
#include <include/utils/constants.hpp>

void
End_game::execute(Station& station, Iinterface& interface) {
  interface.clear();
  if (station.end_game()) {
    interface.end_game(station);
    exit(EXIT_SUCCESS);
  } else {
    std::string msg;
    msg += "Вам не хватает ресурсов. Для конца игры необходимо: \n";
    msg += "Биты: " + std::to_string(END_GAME_BITS_COST) + "\n";
    msg += "Энергия: " + std::to_string(END_GAME_ENEGY_COST);
    interface.problem_output(msg);
  }
  interface.delay(1500);
}