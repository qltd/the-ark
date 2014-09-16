<?php
/**
 * @file
 * footer_region.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function footer_region_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-footer_contact'] = array(
    'cache' => -1,
    'css_class' => 'footer-contact',
    'custom' => 0,
    'machine_name' => 'footer_contact',
    'module' => 'block',
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
      'omega' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'omega',
        'weight' => 0,
      ),
      'the_ark' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'the_ark',
        'weight' => 0,
      ),
      'the_ark_admin' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'the_ark_admin',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
