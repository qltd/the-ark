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
        'views-637e14a258bd08f8590c64f5e238b1b8' => array(
          'module' => 'views',
          'delta' => '637e14a258bd08f8590c64f5e238b1b8',
          'region' => 'content',
          'weight' => '1',
        ),
        'views-tabs-tab_toggles' => array(
          'module' => 'views',
          'delta' => 'tabs-tab_toggles',
          'region' => 'content',
          'weight' => '2',
        ),
        'views-tabs-tabs' => array(
          'module' => 'views',
          'delta' => 'tabs-tabs',
          'region' => 'content',
          'weight' => '3',
        ),
        'views-91d176007d2fc0f60c9a11ccb6bc950f' => array(
          'module' => 'views',
          'delta' => '91d176007d2fc0f60c9a11ccb6bc950f',
          'region' => 'content',
          'weight' => '4',
        ),
        'views-augmented_links-augmented_links' => array(
          'module' => 'views',
          'delta' => 'augmented_links-augmented_links',
          'region' => 'content',
          'weight' => '5',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('content');
  $export['basic'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'club_volunteer';
  $context->description = 'This is the page context for the Club Volunteers page.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'support-the-ark/volunteers/club' => 'support-the-ark/volunteers/club',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webform-client-block-224' => array(
          'module' => 'webform',
          'delta' => 'client-block-224',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the page context for the Club Volunteers page.');
  t('page');
  $export['club_volunteer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'loader_volunteer';
  $context->description = 'This is the page context for the Volunteer Loaders page.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'support-the-ark/volunteers/loaders' => 'support-the-ark/volunteers/loaders',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webform-client-block-223' => array(
          'module' => 'webform',
          'delta' => 'client-block-223',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the page context for the Volunteer Loaders page.');
  t('page');
  $export['loader_volunteer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'membership';
  $context->description = 'This is the Membership page context.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'support-the-ark/membership' => 'support-the-ark/membership',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-17' => array(
          'module' => 'block',
          'delta' => '17',
          'region' => 'content',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the Membership page context.');
  t('page');
  $export['membership'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'tech_volunteer';
  $context->description = 'This is the page context for the Tech Volunteers page.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'support-the-ark/volunteers/tech' => 'support-the-ark/volunteers/tech',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webform-client-block-225' => array(
          'module' => 'webform',
          'delta' => 'client-block-225',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the page context for the Tech Volunteers page.');
  t('page');
  $export['tech_volunteer'] = $context;

  return $export;
}
