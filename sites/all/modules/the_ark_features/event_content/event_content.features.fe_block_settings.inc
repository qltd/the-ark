<?php
/**
 * @file
 * event_content.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function event_content_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['views-events_calendar-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'events_calendar-block_1',
    'module' => 'views',
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

  $export['views-sponsors-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'sponsors-block_1',
    'module' => 'views',
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
