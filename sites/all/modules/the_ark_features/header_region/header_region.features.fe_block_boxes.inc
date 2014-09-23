<?php
/**
 * @file
 * header_region.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function header_region_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the About menu';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'header_navigation_about';
  $fe_block_boxes->body = '<p>Header navigation block for the About menu.</p>
';

  $export['header_navigation_about'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Contact Us menu';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'header_navigation_contact_us';
  $fe_block_boxes->body = '<p>Header navigation block for the Contact Us menu.</p>
';

  $export['header_navigation_contact_us'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Shows & Events menu';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'header_navigation_shows_events';
  $fe_block_boxes->body = '<p>Header navigation block for the Shows &amp; Events menu.</p>
';

  $export['header_navigation_shows_events'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Support the Ark menu';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'header_navigation_support';
  $fe_block_boxes->body = '<p>Header navigation block for the Support the Ark&nbsp;menu.</p>
';

  $export['header_navigation_support'] = $fe_block_boxes;

  return $export;
}
