<?php
/**
 * @file
 * footer_region.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function footer_region_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-footer.
  $menus['menu-footer'] = array(
    'menu_name' => 'menu-footer',
    'title' => 'Footer',
    'description' => 'This menu is displayed in the <em>Footer</em> region.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Footer');
  t('This menu is displayed in the <em>Footer</em> region.');


  return $menus;
}
