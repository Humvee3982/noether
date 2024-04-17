#include <noether_gui/widgets/tool_path_modifiers/uniform_orientation_modifier_widget.h>

#include <noether_tpp/tool_path_modifiers/uniform_orientation_modifier.h>

#include <QFormLayout>
#include <QLabel>

namespace noether
{
UniformOrientationModifierWidget::UniformOrientationModifierWidget(QWidget* parent)
  : ToolPathModifierWidget(parent)
{
  auto layout = new QFormLayout(this);

  auto description = new QLabel("Aligns the x-axis of all waypoints with the direction of travel of the first two waypoints.", this);
  description->setWordWrap(true);
  layout->addRow(description);
}

ToolPathModifier::ConstPtr UniformOrientationModifierWidget::create() const
{
  return std::make_unique<UniformOrientationModifier>();
}

}  // namespace noether
