<?php
/**
 * @file
 * sound_tech_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function sound_tech_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-0ee663c5f2f3a8db70d85fbd39ff2a2a'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => '0ee663c5f2f3a8db70d85fbd39ff2a2a',
    'module' => 'views',
    'node_types' => array(),
    'pages' => 'admin/sound-tech/people',
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
        'region' => 'content_after',
        'status' => 1,
        'theme' => 'the_ark_admin',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 1,
  );

  return $export;
}
