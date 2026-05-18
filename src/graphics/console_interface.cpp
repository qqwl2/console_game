#include "src/core/input.hpp"
#include <chrono>
#include <cstdlib>
#include <include/graphics/console_interface.hpp>
#include <include/utils/ostream_operators.hpp>
#include <iostream>
#include <thread>

void
frame_menu() {
  std::cout << "                    [МЕНЮ УПРАВЛЕНИЯ]" << std::endl;
  std::cout << "| 1. Следующий день                                        |" << std::endl;
  std::cout << "| 2. Купить роботов                                        |" << std::endl;
  std::cout << "| 3. Построить модули                                      |" << std::endl;
  std::cout << "| 4. Улучшить модули                                       |" << std::endl;
  std::cout << "| 5. Управление модулями                                   |" << std::endl;
  std::cout << "| 6. Модульная сборка                                      |" << std::endl;
  std::cout << "| 7. Синтез сознания                                       |" << std::endl;
  std::cout << "| 8. Аналитика                                             |" << std::endl;
  std::cout << "| 9. Постройка квантового навигационного маяка             |" << std::endl;
  std::cout << "| 0. Выход                                                 |" << std::endl;
  std::cout << "Выберите команду > " << std::endl;
}
void
Console_interface::delay(unsigned long milliseconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}
void
Console_interface::clear() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}
void
Console_interface::update_main(Station& station) {
  std::cout << station;
  std::cout << station.get_resources_manager();
  std::cout << station.get_module_manager();
  std::cout << station.get_robot_manager();
  std::cout << station.get_events();
  frame_menu();
}
void
Console_interface::panel_module_toggle(Station& station) {
  std::cout << station.get_module_manager();
  std::cout << "[0] Выход" << std::endl;
  std::cout << "Введите номер модуля для переключения активности: " << std::endl;
}
void
Console_interface::panel_module_upgrade(Station& station) {
  std::cout << station.get_module_manager();
  std::cout << "[0] Выход" << std::endl;
  std::cout << "Введите номер модуля для улучшения: " << std::endl;
}
void
Console_interface::panel_module_purchase(int energy_cost, int bits_cost) {
  std::cout << "[1] Архив           : " << energy_cost << " энергии и " << bits_cost << " битов"
            << std::endl;
  std::cout << "[2] Командный центр : " << energy_cost << " энергии и " << bits_cost << " битов"
            << std::endl;
  std::cout << "[3] Жилой отсек     : " << energy_cost << " энергии и " << bits_cost << " битов"
            << std::endl;
  std::cout << "[4] Генератор       : " << energy_cost << " энергии и " << bits_cost << " битов"
            << std::endl;
  std::cout << "[0] Выход" << std::endl;
  std::cout << "Введите номер опции: " << std::endl;
}
void
Console_interface::panel_robot_purchase(int energy_cost, int bits_cost) {
  std::cout << "[1] Keeper     : " << energy_cost << " энергии и " << bits_cost << " битов"
            << std::endl;
  std::cout << "[2] Integrator : " << energy_cost << " энергии и " << bits_cost << " битов"
            << std::endl;
  std::cout << "[0] Выход" << std::endl;
  std::cout << "Введите номер опции: " << std::endl;
}
void
Console_interface::resources_deficit() {
  std::cout << "Не хватает ресурсов." << std::endl;
}
void
Console_interface::bad_end() {
  std::cout << "смерть" << std::endl;
}
int
Console_interface::request_value(int min, const unsigned long int max) {
  return menu_request(min, max);
}
void
Console_interface::module_synthesis(Station& station) {
  std::cout << station.get_module_manager();
  std::cout << "[0] Выход" << std::endl;
  std::cout << "Введите номера двух модулей для сборки: " << std::endl;
}
void
Console_interface::robot_synthesis(Station& station) {
  std::cout << station.get_robot_manager();
  std::cout << "[0] Выход" << std::endl;
  std::cout << "Введите номера двух роботов для сборки: " << std::endl;
}
void
Console_interface::problem_output(std::string problem) {
  std::cout << problem << std::endl;
}
void
Console_interface::analytics() {
  std::cout << "1. Перекличка" << std::endl;
  std::cout << "2. Инвентаризация" << std::endl;
  std::cout << "3. Оценка потерь" << std::endl;
  std::cout << "0. Выход" << std::endl;
}
void
Console_interface::roll_call(Station& station) {
  std::cout << station.get_robot_manager();
  std::cout << "0. Выход" << std::endl;
}
void
Console_interface::inventory(Station& station) {
  std::cout << station.get_module_manager();
  std::cout << "0. Выход" << std::endl;
}
void
Console_interface::loss_assessment(Station& station) {
  std::cout << "Количество поврежденных роботов: " << station.get_robot_manager().loss_assessment()
            << std::endl;
}
void
Console_interface::end_game(Station& station) {
  std::cout
    << "Ковчег успешно вышел на орбиту Земли-2... Теперь он до скончания веков будет в безопасности"
    << std::endl;
  std::cout << "Поздравляем! Вы достигли конца игры..." << std::endl;
  std::cout << "Это был сложный путь..\nДавайте посмотрим на вашу статистику.." << std::endl;
  std::cout << station.get_end_game_stats();
  std::cout << "А стараться кто будет? Я что ли? Что за позор?" << std::endl;
}