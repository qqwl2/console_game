#pragma once
#include <functional>
#include <include/entities/module.hpp>
#include <include/entities/robot.hpp>
#include <memory>
#include <unordered_map>

template<typename Product>
class Factory {
public:
  virtual std::unique_ptr<Product> create(const std::string& type, int id) = 0;
  virtual ~Factory() = default;
};

class Robot_factory : public Factory<Robot> {
private:
  std::unordered_map<std::string, std::function<std::unique_ptr<Robot>(int id)>> creators;

public:
  Robot_factory();
  std::unique_ptr<Robot> create(const std::string& type, int id) override;
};

class Module_factory : public Factory<Module> {
private:
  std::unordered_map<std::string, std::function<std::unique_ptr<Module>(int id)>> creators;

public:
  Module_factory();
  std::unique_ptr<Module> create(const std::string& type, int id) override;
};