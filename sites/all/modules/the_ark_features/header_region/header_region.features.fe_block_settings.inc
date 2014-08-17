<?php
/**
 * @file
 * header_region.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function header_region_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['system-main-menu'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'main-menu',
    'module' => 'system',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'adminimal' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'adminimal',
        'weight' => 0,
      ),
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
      'the_ark' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'the_ark',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  return $export;
}
