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
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_about';
  $fe_block_boxes->body = '<p><img alt="The Ark " src="/sites/default/files/about.jpg" /></p>

<p><a href="https://www.flickr.com/photos/annarborark/" target="_blank">Look inside the club</a></p>
';

  $export['header_navigation_about'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Our Blog menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_blog';
  $fe_block_boxes->body = 'Text link';

  $export['header_navigation_blog'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Contact Us menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_contact_us';
  $fe_block_boxes->body = '<p><img alt="The Ark Window" src="/sites/default/files/images/contactus.jpg" style="height:270px; width:450px" /></p>

<p><a href="/support-the-ark/volunteers">Get involved</a></p>
';

  $export['header_navigation_contact_us'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Home menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_home';
  $fe_block_boxes->body = '<p><img alt="where music lives" src="/sites/default/files/images/home.png" style="height:109px; width:685px" /></p>
';

  $export['header_navigation_home'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Shows & Events menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_shows_events';
  $fe_block_boxes->body = '<p><img alt="The Ark Ticket Taking" src="/sites/default/files/showsandevents.jpg" /></p>

<p><a href="//shows-events/calendar">View our calendar</a></p>
';

  $export['header_navigation_shows_events'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Support the Ark menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_support';
  $fe_block_boxes->body = '<p><img alt="The Ark Main Street Ann Arbor" src="/sites/default/files/images/supporttheark.jpg" style="height:270px; width:450px" /></p>

<p><a href="/support-the-ark/membership">Become a member today</a></p>
';

  $export['header_navigation_support'] = $fe_block_boxes;

  return $export;
}
