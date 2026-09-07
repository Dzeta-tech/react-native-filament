#pragma once

#include "jsi/RNFHybridObject.h"
#include <filament/Options.h>

namespace margelo {

using namespace filament;

class FogOptionsWrapper : public HybridObject, public FogOptions {
public:
  explicit FogOptionsWrapper() : HybridObject("FogOptions") {}
  explicit FogOptionsWrapper(const FogOptions& options) : HybridObject("FogOptions"), FogOptions(options) {}

  void loadHybridMethods() override {
    registerHybridGetter("distance", &FogOptionsWrapper::getDistance, this);
    registerHybridSetter("distance", &FogOptionsWrapper::setDistance, this);
    registerHybridGetter("cutOffDistance", &FogOptionsWrapper::getCutOffDistance, this);
    registerHybridSetter("cutOffDistance", &FogOptionsWrapper::setCutOffDistance, this);
    registerHybridGetter("maximumOpacity", &FogOptionsWrapper::getMaximumOpacity, this);
    registerHybridSetter("maximumOpacity", &FogOptionsWrapper::setMaximumOpacity, this);
    registerHybridGetter("height", &FogOptionsWrapper::getHeight, this);
    registerHybridSetter("height", &FogOptionsWrapper::setHeight, this);
    registerHybridGetter("heightFalloff", &FogOptionsWrapper::getHeightFalloff, this);
    registerHybridSetter("heightFalloff", &FogOptionsWrapper::setHeightFalloff, this);
    registerHybridGetter("color", &FogOptionsWrapper::getColor, this);
    registerHybridSetter("color", &FogOptionsWrapper::setColor, this);
    registerHybridGetter("density", &FogOptionsWrapper::getDensity, this);
    registerHybridSetter("density", &FogOptionsWrapper::setDensity, this);
    registerHybridGetter("inScatteringStart", &FogOptionsWrapper::getInScatteringStart, this);
    registerHybridSetter("inScatteringStart", &FogOptionsWrapper::setInScatteringStart, this);
    registerHybridGetter("inScatteringSize", &FogOptionsWrapper::getInScatteringSize, this);
    registerHybridSetter("inScatteringSize", &FogOptionsWrapper::setInScatteringSize, this);
    registerHybridGetter("fogColorFromIbl", &FogOptionsWrapper::getFogColorFromIbl, this);
    registerHybridSetter("fogColorFromIbl", &FogOptionsWrapper::setFogColorFromIbl, this);
    registerHybridGetter("enabled", &FogOptionsWrapper::getEnabled, this);
    registerHybridSetter("enabled", &FogOptionsWrapper::setEnabled, this);
  }

private:
  double getDistance() {
    return static_cast<double>(distance);
  }
  void setDistance(double value) {
    distance = static_cast<float>(value);
  }

  double getCutOffDistance() {
    return static_cast<double>(cutOffDistance);
  }
  void setCutOffDistance(double value) {
    cutOffDistance = static_cast<float>(value);
  }

  double getMaximumOpacity() {
    return static_cast<double>(maximumOpacity);
  }
  void setMaximumOpacity(double value) {
    maximumOpacity = static_cast<float>(value);
  }

  double getHeight() {
    return static_cast<double>(height);
  }
  void setHeight(double value) {
    height = static_cast<float>(value);
  }

  double getHeightFalloff() {
    return static_cast<double>(heightFalloff);
  }
  void setHeightFalloff(double value) {
    heightFalloff = static_cast<float>(value);
  }

  std::vector<float> getColor() {
    return {color.r, color.g, color.b};
  }
  void setColor(const std::vector<float>& value) {
    if (value.size() != 3) {
      throw std::invalid_argument("Fog color must contain exactly three values");
    }
    color = {value[0], value[1], value[2]};
  }

  double getDensity() {
    return static_cast<double>(density);
  }
  void setDensity(double value) {
    density = static_cast<float>(value);
  }

  double getInScatteringStart() {
    return static_cast<double>(inScatteringStart);
  }
  void setInScatteringStart(double value) {
    inScatteringStart = static_cast<float>(value);
  }

  double getInScatteringSize() {
    return static_cast<double>(inScatteringSize);
  }
  void setInScatteringSize(double value) {
    inScatteringSize = static_cast<float>(value);
  }

  bool getFogColorFromIbl() {
    return fogColorFromIbl;
  }
  void setFogColorFromIbl(bool value) {
    fogColorFromIbl = value;
  }

  bool getEnabled() {
    return enabled;
  }
  void setEnabled(bool value) {
    enabled = value;
  }
};

} // namespace margelo
