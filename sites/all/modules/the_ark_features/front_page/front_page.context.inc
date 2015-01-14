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
        'views-events_calendar-events_upcoming' => array(
          'module' => 'views',
          'delta' => 'events_calendar-events_upcoming',
          'region' => 'content',
          'weight' => '-10',
        ),
        'block-12' => array(
          'module' => 'block',
          'delta' => '12',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-tabs-homepage_tab_toggles' => array(
          'module' => 'views',
          'delta' => 'tabs-homepage_tab_toggles',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-tabs-homepage_tabs' => array(
          'module' => 'views',
          'delta' => 'tabs-homepage_tabs',
          'region' => 'content',
          'weight' => '-7',
        ),
        'views-billboards-block' => array(
          'module' => 'views',
          'delta' => 'billboards-block',
          'region' => 'content',
          'weight' => '-6',
        ),
        'block-9' => array(
          'module' => 'block',
          'delta' => '9',
          'region' => 'content',
          'weight' => '-5',
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
