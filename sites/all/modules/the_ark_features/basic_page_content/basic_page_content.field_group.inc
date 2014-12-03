<?php
/**
 * @file
 * basic_page_content.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function basic_page_content_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_augmented_links|node|page|form';
  $field_group->group_name = 'group_augmented_links';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Augmented Links',
    'weight' => '5',
    'children' => array(
      0 => 'field_augmented_links',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Augmented Links',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-augmented-links field-group-fieldset',
        'description' => 'Links enhanced with images and descriptions.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_augmented_links|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_expandable_details|node|page|form';
  $field_group->group_name = 'group_expandable_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Expandable Details',
    'weight' => '7',
    'children' => array(
      0 => 'field_expandable_details',
      1 => 'field_expandable_details_heading',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Expandable Details',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-expandable-details field-group-fieldset',
        'description' => 'Expandable list of details with an optional link.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_expandable_details|node|page|form'] = $field_group;

  return $export;
}
