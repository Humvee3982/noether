#pragma once

#include <noether_gui/widgets.h>

#include <noether_tpp/core/tool_path_modifier.h>

namespace noether
{
struct RasterOrganizationModifierWidget : public ToolPathModifierWidget
{
  Q_OBJECT
public:
  RasterOrganizationModifierWidget(QWidget* parent = nullptr);

  ToolPathModifier::ConstPtr create() const override;
};

}  // namespace noether
