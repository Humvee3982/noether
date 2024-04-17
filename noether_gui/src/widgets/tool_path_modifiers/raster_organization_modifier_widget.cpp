#include <noether_gui/widgets/tool_path_modifiers/raster_organization_modifier_widget.h>

#include <noether_tpp/tool_path_modifiers/raster_organization_modifier.h>

#include <QFormLayout>
#include <QLabel>

namespace noether
{
RasterOrganizationModifierWidget::RasterOrganizationModifierWidget(QWidget* parent)
  : ToolPathModifierWidget(parent)
{
  auto layout = new QFormLayout(this);

  auto description = new QLabel("Organizes the tool path into a raster-style pattern.", this);
  description->setWordWrap(true);
  layout->addRow(description);
}

ToolPathModifier::ConstPtr RasterOrganizationModifierWidget::create() const
{
  return std::make_unique<RasterOrganizationModifier>();
}

}  // namespace noether
