#pragma once
#include <exception>

class Power_surge_exception : public std::exception {
public:
  const char* what() const noexcept override { return "Произошел скачок напряжения"; }
};
class Firmware_glitch_exception : public std::exception {
public:
  const char* what() const noexcept override { return "Произошел сбой матриц"; }
};
class Meteor_strike_exception : public std::exception {
public:
  const char* what() const noexcept override { return "На станцию упал метеорит"; }
};
