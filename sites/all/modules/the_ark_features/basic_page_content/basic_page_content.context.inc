<?php
/**
 * @file
 * basic_page_content.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function basic_page_content_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'basic';
  $context->description = '';
  $context->tag = 'content';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'page' => 'page',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-augmented_links-augmented_links' => array(
          'module' => 'views',
          'delta' => 'augmented_links-augmented_links',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-637e14a258bd08f8590c64f5e238b1b8' => array(
          'module' => 'views',
          'delta' => '637e14a258bd08f8590c64f5e238b1b8',
          'region' => 'content',
          'weight' => '1',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('content');
  $export['basic'] = $context;

  return $export;
}
