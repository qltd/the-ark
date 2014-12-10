<?php
/**
 * @file
 * front_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function front_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'This is the front page context';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-1' => array(
          'module' => 'block',
          'delta' => '1',
          'region' => 'hero',
          'weight' => '-10',
        ),
        'block-10' => array(
          'module' => 'block',
          'delta' => '10',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-11' => array(
          'module' => 'block',
          'delta' => '11',
          'region' => 'content',
          'weight' => '-9',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the front page context');
  t('page');
  $export['front'] = $context;

  return $export;
}
