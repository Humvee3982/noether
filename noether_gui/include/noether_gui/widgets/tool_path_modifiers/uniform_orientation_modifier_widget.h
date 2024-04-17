#pragma once

#include <noether_gui/widgets.h>

#include <noether_tpp/core/tool_path_modifier.h>

namespace noether
{
struct UniformOrientationModifierWidget : public ToolPathModifierWidget
{
public:
  UniformOrientationModifierWidget(QWidget* parent = nullptr);
  ToolPathModifier::ConstPtr create() const override;
};

}  // namespace noether
