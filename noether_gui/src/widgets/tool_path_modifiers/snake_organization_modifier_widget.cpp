#include <noether_gui/widgets/tool_path_modifiers/snake_organization_modifier_widget.h>

#include <noether_tpp/tool_path_modifiers/snake_organization_modifier.h>

#include <QFormLayout>
#include <QLabel>

namespace noether
{
SnakeOrganizationModifierWidget::SnakeOrganizationModifierWidget(QWidget* parent)
  : ToolPathModifierWidget(parent)
{
  auto layout = new QFormLayout(this);

  auto description = new QLabel("Organizes the tool path into a snake-style pattern.", this);
  description->setWordWrap(true);
  layout->addRow(description);
}

ToolPathModifier::ConstPtr SnakeOrganizationModifierWidget::create() const
{
  return std::make_unique<SnakeOrganizationModifier>();
}

}  // namespace noether
