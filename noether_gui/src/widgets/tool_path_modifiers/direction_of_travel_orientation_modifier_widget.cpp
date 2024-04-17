#include <noether_gui/widgets/tool_path_modifiers/direction_of_travel_orientation_modifier_widget.h>

#include <noether_tpp/tool_path_modifiers/direction_of_travel_orientation_modifier.h>

#include <QFormLayout>
#include <QLabel>

namespace noether
{
DirectionOfTravelOrientationModifierWidget::DirectionOfTravelOrientationModifierWidget(QWidget* parent)
  : ToolPathModifierWidget(parent)
{
  auto layout = new QFormLayout(this);
  auto description = new QLabel("Aligns the x-axis of all waypoints with the direction of travel between adjacent waypoints", this);
  description->setWordWrap(true);
  layout->addRow(description);
}

ToolPathModifier::ConstPtr DirectionOfTravelOrientationModifierWidget::create() const
{
  return std::make_unique<DirectionOfTravelOrientationModifier>();
}

}  // namespace noether
