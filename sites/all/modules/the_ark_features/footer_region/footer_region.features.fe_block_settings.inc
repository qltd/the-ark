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
    'css_class' => 'footer-contact footer-block',
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

  $export['menu-menu-footer'] = array(
    'cache' => -1,
    'css_class' => 'footer-navigation footer-block',
    'custom' => 0,
    'delta' => 'menu-footer',
    'module' => 'menu',
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
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['the_ark_constant_contact-the_ark_constant_contact'] = array(
    'cache' => 1,
    'css_class' => 'footer-block footer-constant-contact',
    'custom' => 0,
    'delta' => 'the_ark_constant_contact',
    'module' => 'the_ark_constant_contact',
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

  $export['views-f35a682e9097aef774a56c4a68c385fd'] = array(
    'cache' => -1,
    'css_class' => 'footer-block footer-sponsor-featured',
    'custom' => 0,
    'delta' => 'f35a682e9097aef774a56c4a68c385fd',
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
