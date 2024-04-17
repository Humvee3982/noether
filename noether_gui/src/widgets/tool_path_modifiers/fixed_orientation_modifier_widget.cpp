#include <noether_gui/widgets/tool_path_modifiers/fixed_orientation_modifier_widget.h>
#include "ui_vector3d_editor_widget.h"
#include <noether_gui/utils.h>

#include <noether_tpp/tool_path_modifiers/fixed_orientation_modifier.h>
#include <yaml-cpp/yaml.h>

#include <QFormLayout>
#include <QLabel>

namespace noether
{
FixedOrientationModifierWidget::FixedOrientationModifierWidget(QWidget* parent)
  : ToolPathModifierWidget(parent)
  , ui_(new Ui::Vector3dEditor())
{
  auto layout = new QFormLayout(this);
  auto description = new QLabel("Aligns the orientations of each waypoint with the existing waypoint normal (z-axis) and the specified reference x-axis direction", this);
  description->setWordWrap(true);
  layout->addRow(description);

  // Page for the Vector 3d Editor
  auto page = new QWidget();

  ui_->setupUi(page);
  ui_->group_box->setTitle("Reference X Direction");
  layout->addRow(page);

  // Manually set x value
  ui_->double_spin_box_x->setValue(1.0);
}

void FixedOrientationModifierWidget::configure(const YAML::Node& config)
{
  Eigen::Vector3d dir(getEntry<double>(config, "x"), getEntry<double>(config, "y"), getEntry<double>(config, "z"));
  dir.normalize();

  ui_->double_spin_box_x->setValue(dir.x());
  ui_->double_spin_box_y->setValue(dir.y());
  ui_->double_spin_box_z->setValue(dir.z());
}

void FixedOrientationModifierWidget::save(YAML::Node& config) const
{
  config["x"] = ui_->double_spin_box_x->value();
  config["y"] = ui_->double_spin_box_y->value();
  config["z"] = ui_->double_spin_box_z->value();
}

ToolPathModifier::ConstPtr FixedOrientationModifierWidget::create() const
{
  Eigen::Vector3d ref_x_dir(
      ui_->double_spin_box_x->value(), ui_->double_spin_box_y->value(), ui_->double_spin_box_z->value());
  ref_x_dir.normalize();
  return std::make_unique<FixedOrientationModifier>(ref_x_dir);
}

}  // namespace noether
