<?php
/**
 * @file
 * footer_region.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function footer_region_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Contact information for the Ark footer region';
  $fe_block_boxes->format = 'filtered_html';
  $fe_block_boxes->machine_name = 'footer_contact';
  $fe_block_boxes->body = '<p>The Ark</p>

<p>316 S. Main St.</p>

<p>Ann Arbor, MI 48104</p>

<p>Office: (734) 761-1800</p>
';

  $export['footer_contact'] = $fe_block_boxes;

  return $export;
}
