<?php
/**
 * @file
 * sound_tech_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function sound_tech_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|node|sound_tech|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'sound_tech';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Admin',
    'weight' => '7',
    'children' => array(
      0 => 'field_event',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Admin',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-admin field-group-fieldset',
        'description' => 'The field(s) in this group are automatically populated &mdash; change only when necessary.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_admin|node|sound_tech|form'] = $field_group;

  return $export;
}
