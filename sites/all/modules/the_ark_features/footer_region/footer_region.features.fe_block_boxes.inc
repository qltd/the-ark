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
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'footer_contact';
  $fe_block_boxes->body = '<p class="contact-organization footer-paragraph">The Ark</p>
<p class="contact-street-address footer-paragraph">316 S. Main St.</p>
<p class="contact-city-state-zip footer-paragraph"><span class="locality">Ann Arbor</span>, <span class="region">MI</span> <span class="postal-code">48104</span></p>
<p class="contact-telephone footer-paragraph">Office: <a class="phone-office" href="tel:+7347611800">(734) 761-1800</a></p>
';

  $export['footer_contact'] = $fe_block_boxes;

  return $export;
}
