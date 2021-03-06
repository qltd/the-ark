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
  $context->name = 'about';
  $context->description = 'This is the About page context.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'about' => 'about',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-quotes_display-block' => array(
          'module' => 'views',
          'delta' => 'quotes_display-block',
          'region' => 'content',
          'weight' => '8',
        ),
        'views-billboards-block_1' => array(
          'module' => 'views',
          'delta' => 'billboards-block_1',
          'region' => 'content',
          'weight' => '9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the About page context.');
  t('page');
  $export['about'] = $context;

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
        'views-tabs-tab_toggles' => array(
          'module' => 'views',
          'delta' => 'tabs-tab_toggles',
          'region' => 'content',
          'weight' => '1',
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
          'weight' => '5',
        ),
        'views-augmented_links-augmented_links' => array(
          'module' => 'views',
          'delta' => 'augmented_links-augmented_links',
          'region' => 'content',
          'weight' => '7',
        ),
        'views-related_links-related_pages' => array(
          'module' => 'views',
          'delta' => 'related_links-related_pages',
          'region' => 'content',
          'weight' => '11',
        ),
        'views-sponsors_for_basic_pages-block' => array(
          'module' => 'views',
          'delta' => 'sponsors_for_basic_pages-block',
          'region' => 'content',
          'weight' => '9',
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
  $context->name = 'contact_us';
  $context->description = 'This is the Contact Us page context.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'contact' => 'contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webform-client-block-294' => array(
          'module' => 'webform',
          'delta' => 'client-block-294',
          'region' => 'content',
          'weight' => '5',
        ),
        'block-18' => array(
          'module' => 'block',
          'delta' => '18',
          'region' => 'content',
          'weight' => '6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the Contact Us page context.');
  t('page');
  $export['contact_us'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'corporate_sponsorhip';
  $context->description = 'This is the page context for the Corporate Sponsorship page.';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'support-the-ark/corporate-sponsorship' => 'support-the-ark/corporate-sponsorship',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-sponsors-block_1' => array(
          'module' => 'views',
          'delta' => 'sponsors-block_1',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('This is the page context for the Corporate Sponsorship page.');
  t('page');
  $export['corporate_sponsorhip'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'feedback';
  $context->description = '';
  $context->tag = 'page';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'feedback' => 'feedback',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'webform-client-block-71' => array(
          'module' => 'webform',
          'delta' => 'client-block-71',
          'region' => 'content',
          'weight' => '0',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('page');
  $export['feedback'] = $context;

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
