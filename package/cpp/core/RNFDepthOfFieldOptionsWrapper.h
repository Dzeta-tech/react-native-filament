#pragma once

#include "jsi/RNFHybridObject.h"
#include <filament/Options.h>

namespace margelo {

using namespace filament;

class DepthOfFieldOptionsWrapper : public HybridObject, public DepthOfFieldOptions {
public:
  explicit DepthOfFieldOptionsWrapper() : HybridObject("DepthOfFieldOptions") {}
  explicit DepthOfFieldOptionsWrapper(const DepthOfFieldOptions& options)
      : HybridObject("DepthOfFieldOptions"), DepthOfFieldOptions(options) {}

  void loadHybridMethods() override {
    registerHybridGetter("cocScale", &DepthOfFieldOptionsWrapper::getCocScale, this);
    registerHybridSetter("cocScale", &DepthOfFieldOptionsWrapper::setCocScale, this);
    registerHybridGetter("cocAspectRatio", &DepthOfFieldOptionsWrapper::getCocAspectRatio, this);
    registerHybridSetter("cocAspectRatio", &DepthOfFieldOptionsWrapper::setCocAspectRatio, this);
    registerHybridGetter("maxApertureDiameter", &DepthOfFieldOptionsWrapper::getMaxApertureDiameter, this);
    registerHybridSetter("maxApertureDiameter", &DepthOfFieldOptionsWrapper::setMaxApertureDiameter, this);
    registerHybridGetter("enabled", &DepthOfFieldOptionsWrapper::getEnabled, this);
    registerHybridSetter("enabled", &DepthOfFieldOptionsWrapper::setEnabled, this);
    registerHybridGetter("filter", &DepthOfFieldOptionsWrapper::getFilter, this);
    registerHybridSetter("filter", &DepthOfFieldOptionsWrapper::setFilter, this);
    registerHybridGetter("nativeResolution", &DepthOfFieldOptionsWrapper::getNativeResolution, this);
    registerHybridSetter("nativeResolution", &DepthOfFieldOptionsWrapper::setNativeResolution, this);
    registerHybridGetter("foregroundRingCount", &DepthOfFieldOptionsWrapper::getForegroundRingCount, this);
    registerHybridSetter("foregroundRingCount", &DepthOfFieldOptionsWrapper::setForegroundRingCount, this);
    registerHybridGetter("backgroundRingCount", &DepthOfFieldOptionsWrapper::getBackgroundRingCount, this);
    registerHybridSetter("backgroundRingCount", &DepthOfFieldOptionsWrapper::setBackgroundRingCount, this);
    registerHybridGetter("fastGatherRingCount", &DepthOfFieldOptionsWrapper::getFastGatherRingCount, this);
    registerHybridSetter("fastGatherRingCount", &DepthOfFieldOptionsWrapper::setFastGatherRingCount, this);
    registerHybridGetter("maxForegroundCOC", &DepthOfFieldOptionsWrapper::getMaxForegroundCOC, this);
    registerHybridSetter("maxForegroundCOC", &DepthOfFieldOptionsWrapper::setMaxForegroundCOC, this);
    registerHybridGetter("maxBackgroundCOC", &DepthOfFieldOptionsWrapper::getMaxBackgroundCOC, this);
    registerHybridSetter("maxBackgroundCOC", &DepthOfFieldOptionsWrapper::setMaxBackgroundCOC, this);
  }

private:
  double getCocScale() {
    return static_cast<double>(cocScale);
  }
  void setCocScale(double value) {
    cocScale = static_cast<float>(value);
  }

  double getCocAspectRatio() {
    return static_cast<double>(cocAspectRatio);
  }
  void setCocAspectRatio(double value) {
    cocAspectRatio = static_cast<float>(value);
  }

  double getMaxApertureDiameter() {
    return static_cast<double>(maxApertureDiameter);
  }
  void setMaxApertureDiameter(double value) {
    maxApertureDiameter = static_cast<float>(value);
  }

  bool getEnabled() {
    return enabled;
  }
  void setEnabled(bool value) {
    enabled = value;
  }

  std::string getFilter() {
    switch (filter) {
      case DepthOfFieldOptions::Filter::NONE:
        return "NONE";
      case DepthOfFieldOptions::Filter::UNUSED:
        return "UNUSED";
      case DepthOfFieldOptions::Filter::MEDIAN:
        return "MEDIAN";
    }
    throw std::invalid_argument("Invalid depth-of-field filter value");
  }
  void setFilter(const std::string& value) {
    if (value == "NONE") {
      filter = DepthOfFieldOptions::Filter::NONE;
    } else if (value == "UNUSED") {
      filter = DepthOfFieldOptions::Filter::UNUSED;
    } else if (value == "MEDIAN") {
      filter = DepthOfFieldOptions::Filter::MEDIAN;
    } else {
      throw std::invalid_argument("Invalid depth-of-field filter value");
    }
  }

  bool getNativeResolution() {
    return nativeResolution;
  }
  void setNativeResolution(bool value) {
    nativeResolution = value;
  }

  double getForegroundRingCount() {
    return static_cast<double>(foregroundRingCount);
  }
  void setForegroundRingCount(double value) {
    foregroundRingCount = static_cast<uint8_t>(value);
  }

  double getBackgroundRingCount() {
    return static_cast<double>(backgroundRingCount);
  }
  void setBackgroundRingCount(double value) {
    backgroundRingCount = static_cast<uint8_t>(value);
  }

  double getFastGatherRingCount() {
    return static_cast<double>(fastGatherRingCount);
  }
  void setFastGatherRingCount(double value) {
    fastGatherRingCount = static_cast<uint8_t>(value);
  }

  double getMaxForegroundCOC() {
    return static_cast<double>(maxForegroundCOC);
  }
  void setMaxForegroundCOC(double value) {
    maxForegroundCOC = static_cast<uint16_t>(value);
  }

  double getMaxBackgroundCOC() {
    return static_cast<double>(maxBackgroundCOC);
  }
  void setMaxBackgroundCOC(double value) {
    maxBackgroundCOC = static_cast<uint16_t>(value);
  }
};

} // namespace margelo
