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
  $fe_block_boxes->body = '<img alt="The Ark " src="/sites/default/files/about.jpg" /> <a href="https://www.flickr.com/photos/annarborark/" target="_blank">Look inside the club</a>';

  $export['header_navigation_about'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Our Blog menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_blog';
  $fe_block_boxes->body = '<img alt="Find Your Folk logo" src="/sites/default/files/FindYourFolk_0.jpg" /> <a href="http://www.findyourfolk.org/" target="_blank">Visit our blog</a>';

  $export['header_navigation_blog'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Tickets View Calendar menu.';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_calendar';
  $fe_block_boxes->body = '<img alt="Close up of a microphone on the Ark stage" src="/sites/default/files/tickets_shows.jpg" />
<a href="/shows-events/calendar" target="_blank">View Calendar</a>';

  $export['header_navigation_calendar'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Contact Us menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_contact_us';
  $fe_block_boxes->body = '<img alt="The Ark Window" src="/sites/default/files/images/contactus.jpg" /> <a href="/support-the-ark/volunteers">Get involved</a>';

  $export['header_navigation_contact_us'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Home menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_home';
  $fe_block_boxes->body = '<a href="/"><img alt="where music lives" src="/sites/default/files/images/home.png" /></a>';

  $export['header_navigation_home'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Listen Spotify menu.';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_listen_spotify';
  $fe_block_boxes->body = '<img alt="Spotify logo" src="/sites/default/files/listen_spotify.jpg" />
<a href="https://play.spotify.com/user/annarborark" target="_blank">Spotify</a>';

  $export['header_navigation_listen_spotify'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Listen Youtube Menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_listen_youtube';
  $fe_block_boxes->body = '<img alt="YouTube logo" src="/sites/default/files/listen_youtube.jpg" /> <a href="https://www.youtube.com/channel/UCcFtcouM8zBvh2SojeyAYUg" target="_blank">YouTube</a>';

  $export['header_navigation_listen_youtube'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Shows & Events menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_shows_events';
  $fe_block_boxes->body = '<img alt="The Ark Ticket Taking" src="/sites/default/files/showsandevents.jpg" /> <a href="/shows-events/calendar">View our calendar</a>';

  $export['header_navigation_shows_events'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Support the Ark menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_support';
  $fe_block_boxes->body = '<img alt="The Ark Main Street Ann Arbor" src="/sites/default/files/images/supporttheark.jpg" /> <a href="/support-the-ark/membership">Become a member today</a>';

  $export['header_navigation_support'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Header navigation block for the Tickets Ticket Info Menu';
  $fe_block_boxes->format = 'admin_html';
  $fe_block_boxes->machine_name = 'header_navigation_ticket_info';
  $fe_block_boxes->body = '<img alt="Customer handing ticket to employee at the Ark ticket window" src="/sites/default/files/tickets_policy.jpg" /> <a href="/shows-events/ticket-information" target="_blank">Ticket Information</a>';

  $export['header_navigation_ticket_info'] = $fe_block_boxes;

  return $export;
}
