#include <noether_gui/widgets/tool_path_modifiers/standard_edge_paths_organization_modifier_widget.h>
#include "ui_vector3d_editor_widget.h"
#include <noether_gui/utils.h>

#include <noether_tpp/tool_path_modifiers/standard_edge_paths_organization_modifier.h>
#include <yaml-cpp/yaml.h>

#include <QFormLayout>
#include <QLabel>

namespace noether
{
StandardEdgePathsOrganizationModifierWidget::StandardEdgePathsOrganizationModifierWidget(QWidget* parent)
  : ToolPathModifierWidget(parent)
  , ui_(new Ui::Vector3dEditor())
{
  auto layout = new QFormLayout(this);

  auto description = new QLabel("Organizes a set of tool paths into a standard configuration for edge paths.", this);
  description->setWordWrap(true);
  layout->addRow(description);

  auto page = new QWidget();
  ui_->setupUi(page);
  ui_->group_box->setTitle("Start Reference");
  layout->addRow(page);
}

void StandardEdgePathsOrganizationModifierWidget::configure(const YAML::Node& config)
{
  ui_->double_spin_box_x->setValue(getEntry<double>(config, "x"));
  ui_->double_spin_box_y->setValue(getEntry<double>(config, "y"));
  ui_->double_spin_box_z->setValue(getEntry<double>(config, "z"));
}

void StandardEdgePathsOrganizationModifierWidget::save(YAML::Node& config) const
{
  config["x"] = ui_->double_spin_box_x->value();
  config["y"] = ui_->double_spin_box_y->value();
  config["z"] = ui_->double_spin_box_z->value();
}

ToolPathModifier::ConstPtr StandardEdgePathsOrganizationModifierWidget::create() const
{
  Eigen::Vector3d start_ref(
      ui_->double_spin_box_x->value(), ui_->double_spin_box_y->value(), ui_->double_spin_box_z->value());
  return std::make_unique<StandardEdgePathsOrganizationModifier>(start_ref);
}

}  // namespace noether
