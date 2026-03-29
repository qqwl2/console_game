#pragma once
#include <string>

class Robot {
  friend std::ostream& operator<<(std::ostream& os, const Robot& robot);

private:
  const int id;

protected:
  std::string  name;
  int          chassis_integrity;
  int          firmware_integrity;
  bool         is_homeless;
  int          energy;
  int          bits;
  int          occupied_place;
  const float  resources_efficiency;
  unsigned int day;

public:
  Robot(const int id, const float resources_efficiency);
  virtual std::string get_type_str() const = 0;
  const int           get_chassis_integrity() const;
  const int           get_firmware_integrity() const;
  const int           get_energy() const;
  const int           get_bits() const;
  const int           get_occupied_place() const;
  void                set_is_homeless(const bool data);
  const int           get_id() const;
  const int           get_day() const;
  void                new_day();
  Robot&              operator--();
  Robot&              operator++();
  int                 operator+(Robot& robot);
  virtual ~Robot() = default;
};