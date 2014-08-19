<?php
/**
 * @file
 * front_page.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function front_page_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'The hero-space text for the Ark';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'hero_about';
  $fe_block_boxes->body = '<p class="hero-about-paragraph">Live music over 300 nights each year in one of the best listening rooms anywhere</p>
';

  $export['hero_about'] = $fe_block_boxes;

  return $export;
}
