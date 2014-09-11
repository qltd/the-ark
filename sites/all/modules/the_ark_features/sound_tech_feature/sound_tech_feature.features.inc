<?php
/**
 * @file
 * sound_tech_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function sound_tech_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function sound_tech_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function sound_tech_feature_node_info() {
  $items = array(
    'sound_tech' => array(
      'name' => t('Sound Tech Event'),
      'base' => 'node_content',
      'description' => t('Sound tech information for a show or event.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'sound_tech_page' => array(
      'name' => t('Sound Tech Page'),
      'base' => 'node_content',
      'description' => t('Page for the administrative sound tech section of the site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
