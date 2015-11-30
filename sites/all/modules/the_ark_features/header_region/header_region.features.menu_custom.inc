<?php
/**
 * @file
 * header_region.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function header_region_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
  );
  // Exported menu: menu-shortcuts.
  $menus['menu-shortcuts'] = array(
    'menu_name' => 'menu-shortcuts',
    'title' => 'Shortcuts',
    'description' => 'Shortcuts to nested menu items that will be displayed alongside top-level navigation (the <em>Main</em> menu).',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('Shortcuts');
  t('Shortcuts to nested menu items that will be displayed alongside top-level navigation (the <em>Main</em> menu).');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
