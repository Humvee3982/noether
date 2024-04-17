#pragma once

#include <noether_gui/widgets/tool_path_modifiers/linear_approach_modifier_widget.h>

namespace noether
{
class LinearDepartureToolPathModifierWidget : public LinearApproachToolPathModifierWidget
{
  Q_OBJECT

public:
  LinearDepartureToolPathModifierWidget(QWidget* parent = nullptr);

  ToolPathModifier::ConstPtr create() const override;
};

}  // namespace noether
