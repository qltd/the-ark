<?php
/**
 * @file
 * front_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function front_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_node_info().
 */
function front_page_node_info() {
  $items = array(
    'hero_image' => array(
      'name' => t('Hero Image'),
      'base' => 'node_content',
      'description' => t('Images that are displayed in the header on the front page. '),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
