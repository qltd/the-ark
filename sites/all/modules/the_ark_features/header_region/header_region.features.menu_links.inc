<?php
/**
 * @file
 * header_region.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function header_region_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_the-ark:<front>
  $menu_links['main-menu_the-ark:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'The Ark',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_the-ark:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('The Ark');


  return $menu_links;
}
