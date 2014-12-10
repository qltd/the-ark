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
  $fe_block_boxes->body = '<img alt="Exterior shot of The Ark in Ann Arbor, Michigan" src="/sites/default/files/the-ark_fullFeat.png" />
<p>Located on Main Street in downtown Ann Arbor. We have a page for <a href="#">things to do and see</a> in the area, as well as <a href="/contact/directions-parking">driving directions</a> to the club. If you’d like to get in touch, please <a href="/contact">contact us</a>.</p>
';

  $export['home_full_feature'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Left small feature for homepage.';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'home_small_feature_left';
  $fe_block_boxes->body = '<a href="https://www.flickr.com/photos/annarborark/" target="_blank"><img alt="Hoots performing live on the ark stage" src="/sites/default/files/hoots_smFeat.png" /></a>
<h3>Photos</h3>

<p>Browse through Ark imagery from past to present.</p>
';

  $export['home_small_feature_left'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Right small feature for home page. ';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'home_small_feature_right';
  $fe_block_boxes->body = '<a href="/shows-events/events-workshops/folk-festival" target="_self"><img alt="38th ann arbor folk festival logo" src="/sites/default/files/folk-fest-logo_smFeat.png" /></a>
<h3>Announcements</h3>

<p>The Folk Festival is coming up soon.&nbsp;Get your tickets now!</p>
';

  $export['home_small_feature_right'] = $fe_block_boxes;

  return $export;
}
