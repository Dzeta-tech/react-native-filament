#pragma once

#include "jsi/RNFHybridObject.h"
#include <filament/Options.h>

namespace margelo {

using namespace filament;

class VignetteOptionsWrapper : public HybridObject, public VignetteOptions {
public:
  explicit VignetteOptionsWrapper() : HybridObject("VignetteOptions") {}
  explicit VignetteOptionsWrapper(const VignetteOptions& options) : HybridObject("VignetteOptions"), VignetteOptions(options) {}

  void loadHybridMethods() override {
    registerHybridGetter("midPoint", &VignetteOptionsWrapper::getMidPoint, this);
    registerHybridSetter("midPoint", &VignetteOptionsWrapper::setMidPoint, this);
    registerHybridGetter("roundness", &VignetteOptionsWrapper::getRoundness, this);
    registerHybridSetter("roundness", &VignetteOptionsWrapper::setRoundness, this);
    registerHybridGetter("feather", &VignetteOptionsWrapper::getFeather, this);
    registerHybridSetter("feather", &VignetteOptionsWrapper::setFeather, this);
    registerHybridGetter("color", &VignetteOptionsWrapper::getColor, this);
    registerHybridSetter("color", &VignetteOptionsWrapper::setColor, this);
    registerHybridGetter("enabled", &VignetteOptionsWrapper::getEnabled, this);
    registerHybridSetter("enabled", &VignetteOptionsWrapper::setEnabled, this);
  }

private:
  double getMidPoint() {
    return static_cast<double>(midPoint);
  }
  void setMidPoint(double value) {
    midPoint = static_cast<float>(value);
  }

  double getRoundness() {
    return static_cast<double>(roundness);
  }
  void setRoundness(double value) {
    roundness = static_cast<float>(value);
  }

  double getFeather() {
    return static_cast<double>(feather);
  }
  void setFeather(double value) {
    feather = static_cast<float>(value);
  }

  std::vector<float> getColor() {
    return {color.r, color.g, color.b, color.a};
  }
  void setColor(const std::vector<float>& value) {
    if (value.size() != 4) {
      throw std::invalid_argument("Vignette color must contain exactly four values");
    }
    color = {value[0], value[1], value[2], value[3]};
  }

  bool getEnabled() {
    return enabled;
  }
  void setEnabled(bool value) {
    enabled = value;
  }
};

} // namespace margelo
