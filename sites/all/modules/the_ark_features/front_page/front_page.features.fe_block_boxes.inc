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

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Full-width feature for the homepage.';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'home_full_feature';
  $fe_block_boxes->body = '<img alt="Exterior shot of The Ark in Ann Arbor, Michigan" src="../sites/all/themes/the_ark/images/the-ark_fullFeat.png" />
<p>We’re located on Main Street in downtown Ann Arbor, Michigan. See <a href="/contact/directions-parking">driving directions</a> to the club. If you’d like to get in touch, please <a href="/contact">contact us</a>.</p>
';

  $export['home_full_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Main full-width feature on the homepage.';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'home_full_feature_main';
  $fe_block_boxes->body = '<p>Considered one of the top music clubs in the world, The Ark is renowned for the quality and breadth of its programming. The Ark is an intimate 400-seat club presenting performers who fall into the wide-ranging genres of folk and roots music.&nbsp;</p>

<p><a href="/about/history" target="_self">Our history</a></p>
';

  $export['home_full_feature_main'] = $fe_block_boxes;

  return $export;
}
