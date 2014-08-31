<?php
/**
 * @file
 * event_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function event_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_node_info().
 */
function event_content_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('A show or event that will have a distinct page, and representation on the calendar.'),
      'has_title' => '1',
      'title_label' => t('Artist or Event Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
