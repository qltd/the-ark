<?php
/**
 * @file
 * footer_region.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function footer_region_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'footer';
  $context->description = 'This is the sitewide context for the footer region';
  $context->tag = 'region';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'the_ark_constant_contact-the_ark_constant_contact' => array(
          'module' => 'the_ark_constant_contact',
          'delta' => 'the_ark_constant_contact',
          'region' => 'footer',
          'weight' => '-10',
        ),
        'views-f35a682e9097aef774a56c4a68c385fd' => array(
          'module' => 'views',
          'delta' => 'f35a682e9097aef774a56c4a68c385fd',
          'region' => 'footer',
          'weight' => '-9',
        ),
        'block-2' => array(
          'module' => 'block',
          'delta' => '2',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'menu-menu-footer' => array(
          'module' => 'menu',
          'delta' => 'menu-footer',
          'region' => 'footer',
          'weight' => '-7',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the sitewide context for the footer region');
  t('region');
  $export['footer'] = $context;

  return $export;
}
